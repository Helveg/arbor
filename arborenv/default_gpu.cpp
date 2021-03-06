#ifdef ARB_HAVE_GPU

#include "gpu_api.hpp"

namespace arbenv {

// When arbor does not have CUDA support, return -1, which always
// indicates that no GPU is available.
int default_gpu() {
    int n;
    if (get_device_count(&n)) {
        // if 1 or more GPUs, take the first one.
        // else return -1 -> no gpu.
        return n? 0: -1;
    }
    return -1;
}

} // namespace arbenv

#else // ifdef ARB_HAVE_GPU

namespace arbenv {

int default_gpu() {
    return -1;
}

} // namespace arbenv

#endif // ifdef ARB_HAVE_GPU

