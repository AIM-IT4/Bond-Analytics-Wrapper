
# Bond Analytics Library

## Overview

The Bond Analytics Library is a Python wrapper for C++ implementations of various bond analytics calculations. It aims to provide fast and accurate methods for calculating bond metrics such as clean price, dirty price, convexity, duration, modified duration, periodic cash flows, and yield curve dynamics.

## Features

- **Clean Price**: Calculate the clean price of a bond given its face value, coupon rate, yield, and number of periods.
- **Dirty Price**: Calculate the dirty price of a bond based on its clean price and accrued interest.
- **Convexity**: Calculate the convexity of a bond.
- **Duration**: Calculate the Macaulay duration of a bond.
- **Modified Duration**: Calculate the modified duration of a bond.
- **Periodic Cash Flows**: Generate the periodic cash flows for a bond.
- **Yield Curve Dynamics**: Simplified yield curve dynamics for illustrative purposes.

## Installation

1. Clone the repository
2. Navigate to the project directory
3. Compile the C++ code into a Python-compatible shared library using the following command:

```bash
c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` BondAnalytics.cpp -o BondAnalytics`python3-config --extension-suffix`
```

## Usage

Here is a simple example that demonstrates how to use the library in Python:

```python
import BondAnalytics

bond = BondAnalytics.BondAnalytics()
clean_price = bond.clean_price(1000, 0.05, 0.04, 5)
print("Clean Price:", clean_price)
```

## Contributing

Contributions are welcome! Please read the contributing guidelines before making any changes.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
