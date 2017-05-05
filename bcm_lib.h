

#define BCM2708_PERI_BASE	0x20000000
#define GPIO_BASE		(BCM2708_PERI_BASE + 0x200000) /*GPIO controller*/
#define BLOCK_SIZE		(4*1024)

typedef unsigned int	UINT;

struct bcm2835_peripherial {
	unsigned long 	addr_p;
	int 		mem_fd;
	void	   	*map;
	volatile UINT	*addr;
};

typedef struct bcm2835_peripherial bcm2835;

extern struct bcm2835_peripherial gpio;

int map_peripheral (bcm2835 * p);

int unmap_peripheral (bcm2835 * p);
