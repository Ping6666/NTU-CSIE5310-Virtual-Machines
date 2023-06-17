# hw1

## Config

### system environment

```bash
sudo apt update
sudo apt install git

# gemu (compile)
sudo apt install build-essential ninja-build pkg-config
sudo apt install libglib2.0-dev libpixman-1-dev

# linux
sudo apt install gcc-aarch64-linux-gnu
sudo apt install flex bison openssl libssl-dev
```

### VM

Failed to mount Mount unit for snapd, revision 17954.

```bash=
sudo apt purge snapd
sudo apt autoremove

# then reboot the qemu kvm
```

### SSH setting

#### server

> in the vm (qemu kvm)

To initialize the SSH configuration, use the command `dpkg-reconfigure openssh-server`. Afterwards, navigate to the file `/etc/ssh/sshd_config` and remove the commented code preceding "PubkeyAuthentication" and "AuthorizedKeysFile".

#### client

> in the vm (host)

To generate an SSH key, use the command `ssh-keygen`. Next, copy the contents of the file `./.ssh/id_rsa.pub` from the client and paste them into the file `/root/.ssh/authorized_keys` on the server. Once completed, can now enjoy SSH access.

### Git

```bash
# diif
git diff > file_name.patch

# apply & revert apply
git apply file_name.patch
git apply -R file_name.patch
```

## write-up

1. Locate the entry point for the guest, such as `kvm_arch_vcpu_ioctl_run`.
2. Verify the values of the general-purpose registers and modify them according to the required pattern to pass the blocker.
