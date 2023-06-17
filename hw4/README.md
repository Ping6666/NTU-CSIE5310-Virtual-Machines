# hw4

## write-up

### Docker Container

Client / Server Model

```bash
docker compose up -d [--build]
docker compose down

docker ps [-a]
docker inspect -f '{{ .Mounts }}' {CONTAINER_ID}
docker exec -t -i {CONTAINER_NAMES} /bin/bash
```

### QEMU

bypass the Linux login authentication

1. Locate the precise section of code that is responsible for generating intermediate code for the basic block 'translation block'. In this scenario, the objective is to translate AArch64 instructions into intermediate code, such as in the function `aarch64_tr_translate_insn`.
2. Identify the instructions using the `pc` and `insn` values obtained from `objdump`, and substitute them with instructions that produce the same outcome as the execution when the `pam_authenticate()` function successfully verifies the correctness of the password.
