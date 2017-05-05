#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "bcm_lib.h"
#include "macros.h"

struct bcm2835_peripherial gpio = {GPIO_BASE};

int map_peripheral (bcm2835 * p){

	//Open /dev/mem
	printf("begin map peri\n");
	
	if((p->mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0 ) {
		
		printf("Failed to open /dev/mem. %s\n", strerror(errno));
		return -1;
	}
	
	printf("mem_fd %d \n", p->mem_fd);
	p->map = mmap( NULL, BLOCK_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED,p->mem_fd, p->addr_p);
	
	if(p->map == MAP_FAILED){
	
		printf("error %p \n", p->map);
		perror("mmap error");
		return -1;
	}
	
	p->addr = (volatile UINT *) p->map;
	
	return 0;
}

int unmap_peripheral (bcm2835 * p){

	printf("Unmap\n");
	munmap(p->map, BLOCK_SIZE);
	return 0;
}
