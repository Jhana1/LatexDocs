class BenchmarkObj  
{
protected:
    cudaDeviceProp mDeviceInfo;
    BenchmarkConfig mConfig;

public:
    std::string DeviceName();
    
    BenchmarkObj();
    BenchmarkObj(int device);
    BenchmarkObj(std::map<std::string, std::string> config);

    std::string Report();

    // Trivial
    void BenchMemBandwidth();

    // Simple
    void BenchMap();
    void BenchReduce();
    void BenchScan();

    // Intermediate
    void BenchMatrixMultiplySimple();
    void BenchMatrixAddition();

    // Complex
    void BenchMatrixMultiplyStreaming();
    void BenchBreadthFirstTraversal();
    void BenchDepthFirstTraversal();
};



