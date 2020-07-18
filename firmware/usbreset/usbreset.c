// HACK! Because either/or the PICkit2 or pk2cmd suck.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>

int main(int argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "Usage: usbreset <file>\n");
		return 1;
	}

	char *file = argv[1];
	int fd = open(file, O_WRONLY);
	if(fd < 0) {
		fprintf(stderr, "Error opening file\n");
		return 1;
	}

	if(ioctl(fd, USBDEVFS_RESET, 0) < 0) {
		fprintf(stderr, "ioctl error\n");
	}

	close(fd);

	return 0;
}