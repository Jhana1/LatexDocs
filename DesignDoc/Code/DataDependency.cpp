double mean = 0;

// Calculate Mean
for (size_t i = 0; i < ELEMS; ++i)
    mean += vec[i]/ELEMS;

// Data Dependency: Relies on Calculated Mean
for (size_t i = 0; i < ELEMS; ++i)
    vec[i] = abs(vec[i] - mean);

// Data Dependency: Relies on other value of vec
for (size_t i = 0; i < ELEMS; ++i)
    vec[i] = vec[vec[i]]; 
