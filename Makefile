arch ?= x86_64
kernel := build/kernel-$(arch).bin
iso := build/os-$(arch).iso

linker_script := lnk/arch/$(arch)/link.ld

grub_cfg := workers/arch/$(arch)/grub.cfg

assembly_source_files := $(wildcard src/arch/$(arch)/*.asm)
assembly_object_files := $(patsubst src/arch/$(arch)/%.asm, build/arch/$(arch)/%.o, $(assembly_source_files))

.PHONY: all clean run iso

all: $(kernel)

clean:
	@echo "Cleaning all..."
	@rm -r build

run: $(iso)
	@echo "Running with qemu"
	@qemu-system-x86_64 -cdrom $(iso) 2> /dev/null

iso: $(iso)

$(iso): $(kernel) $(grub_cfg)
	@echo "Creating iso from binary"
	@mkdir -p build/isofiles/boot/grub
	@cp $(kernel) build/isofiles/boot/kernel.bin
	@cp $(grub_cfg) build/isofiles/boot/grub
	@grub-mkrescue -o $(iso) build/isofiles 2> /dev/null
	@rm -r build/isofiles

$(kernel): $(assembly_object_files) $(linker_script)
	@echo "Linking object files..."
	@ld -n -T $(linker_script) -o $(kernel) $(assembly_object_files)

build/arch/$(arch)/%.o: src/arch/$(arch)/%.asm
	@mkdir -p $(shell dirname $@)
	@echo "Compile $< part"
	@nasm -felf64 $< -o $@
