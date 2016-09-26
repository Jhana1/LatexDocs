out_vec[0] = in_vec[0];
for (size_t i = 1; i < SIZE; ++i)
  out_vec[i] = in_vec[i] + out_vec[i-1];
