#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
    const auto shm_size = 100000U;

    // Create shared memory object and set its size
    const auto fd = shm_open("/myregion", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return 1;
  
    if (ftruncate(fd, shm_size) == -1)
        return 1;

    // Map shared memory object
    void * rptr = mmap(NULL, shm_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (rptr == MAP_FAILED)
        return 1;

    // use it

    // Unmap and destroy shared memory
    munmap(rptr, shm_size);
    shm_unlink("/myregion");


}