### nucaxOS 1

A small graphical hobby operating system written in C with a Windows-like GUI, built from scratch.

## Build Instructions

1. Install a cross-compiler for `x86_64-elf` (see OSDev Wiki).
2. Run `make` to build the kernel.
3. Run `make iso` to generate `nucaxOS.iso`.
4. Test with QEMU: `make run`
5. To boot on real hardware, write `nucaxOS.iso` to a USB: `sudo dd if=nucaxOS.iso of=/dev/sdX bs=4M && sync`
## Features
- GRUB bootloader (Multiboot)
- Basic VGA framebuffer graphics
- Mouse cursor simulation
- Simple windowless GUI
- Taskbar area
- Modular structure for drivers, multitasking, and filesystem

## Future Roadmap
- Real PS/2 mouse and keyboard input
- Window manager and draggable windows
- FAT32 read support
- Preemptive multitasking
- GUI apps framework
