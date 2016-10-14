#include "mc.h"
#include "memlist.h"

#define DEBUG

static void *(*mallocp)(size_t size) = NULL;
static void (*freep)(void *ptr) = NULL;

void my_init(void) __attribute__((constructor)); //告诉gcc把这个函数扔到init section
void my_fini(void) __attribute__((destructor));  //告诉gcc把这个函数扔到fini section


static unsigned long n_malloc  = 0;
// static unsigned long n_calloc  = 0;
// static unsigned long n_realloc = 0;
// static unsigned long n_allocb  = 0;
static unsigned long n_free    = 0;
static item *list = NULL;

static int status = 1;


void my_init(void)
{
    printf("\n\033[1;33m[Hanggi]Memory Detector start running ^ ^\033[0m\n");

    list = new_list();
}
void my_fini(void)
{
    printf("\033[1;33m[Hanggi]Memory Detector finished his work, let's see the result.\033[0m\n\n");

    int res = check_list(list);

    if (res && status > 0) {
        printf("\033[0;32;32m[PASS] Every memory managed well. \033[0m\n");
    }
    if (status == -1) {
        printf("\033[0;32;31m[ERROR] There are some free freed freed memory. check it.\033[0m\n");
    }
}


void* malloc(size_t size)
{
    if (!mallocp) {
		mallocp = /*(void *(*)(size_t))*/dlsym(RTLD_NEXT, "malloc");
	}

    void *ptr;
    ptr = mallocp(size);

	n_malloc += size;

	// 列表
	alloc(list, ptr, size);

	return ptr;
}

void free(void* p)
{
    if (!freep) {
		freep = /*(void (*)(void *))*/dlsym(RTLD_NEXT, "free");
	}
    int i = 1;
    item *tempp = find(list, p);

	if (tempp == NULL){
        printf("\033[0;32;31m[ILLEGAL]This is a ILLEGAL free! @: %p\033[0m\n", p);
        status = -1;
		return ;
	}else if (tempp->cnt <= 0) {
        printf("\033[0;32;31m[ILLEGAL]This is a DOUBLE free! @: %p\033[0m\n", p);
        status = -1;
		return ;
	}else {
		// count the size of free
		n_free += tempp->size;

		// list dealloc
		dealloc(list, p);

		freep(p);
	}

}
