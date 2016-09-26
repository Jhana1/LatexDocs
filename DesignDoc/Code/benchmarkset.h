class BenchmarkSet
{
public:
    BenchmarkSet(std::string benchmarkLocation);
    BenchmarkSet();
    bool Exists(std::string operation) const;
    double Speedup(std::string operation, std::size_t dimension) const;
    double Speedup(std::string operation) const;
    std::tuple<double, double> GetResult(std::string operation, std::size_t dimension) const;
    std::tuple<double, double> LowerUpper(std::string operation, std::size_t dimension) const;

private:
    std::map<std::string, std::map<std::size_t, std::tuple<double, double>>> benchmarks;
    static const std::map<const std::string, const std::size_t> VectorFixtures;
    static const std::map<const std::string, const std::size_t> MatrixFixtures;
};
