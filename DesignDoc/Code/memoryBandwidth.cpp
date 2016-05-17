void BenchmarkObj::BenchMemBandwidth()
{
    size_t size = 10000000;
    uint8_t *h_a, *h_b;
    uint8_t *d_a, *d_b;
    timespec ts, te;

    h_a = (uint8_t*) malloc(sizeof(uint8_t) * size);
    h_b = (uint8_t*) malloc(sizeof(uint8_t) * size);

    vectorFill(h_a, size);
    vectorFill(h_b, size);

    cudaMalloc((void **) &d_a, sizeof(uint8_t) * size);
    cudaMalloc((void **) &d_b, sizeof(uint8_t) * size);

    for (int i = 0; i < 10; ++i)
    {
        clock_gettime(CLOCK_REALTIME, &ts);
        cudaMemcpy(d_a, h_a, sizeof(uint8_t) * size, cudaMemcpyHostToDevice);
        cudaMemcpy(d_b, h_b, sizeof(uint8_t) * size, cudaMemcpyHostToDevice);
        clock_gettime(CLOCK_REALTIME, &te);

        timespec diff = diffTime(ts, te);
        std::cout << diff.tv_sec << "s " << diff.tv_nsec << "ns "
                  << ((float) size / diff.tv_nsec) << "GB/s" <<  std::endl;
    }
    std::cout << std::endl << "INTERNAL" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        clock_gettime(CLOCK_REALTIME, &ts);
        cudaMemcpy(d_a, d_b, sizeof(uint8_t) * size, cudaMemcpyDeviceToDevice);
        cudaMemcpy(d_b, d_a, sizeof(uint8_t) * size, cudaMemcpyDeviceToDevice);
        clock_gettime(CLOCK_REALTIME, &te);

        timespec diff = diffTime(ts, te);
        std::cout << diff.tv_sec << "s " << diff.tv_nsec << "ns "
                  << ((float) size / diff.tv_nsec) << "GB/s" <<  std::endl;
    }
    cudaFree(d_a);
    cudaFree(d_b);
    free(h_a);
    free(h_b);
}
