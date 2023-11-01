
#include <vector>
#include <cmath>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

class BondAnalytics {
public:
    // Calculate clean price of the bond
    double clean_price(double face_value, double coupon_rate, double yield, int periods) {
        double coupon = face_value * coupon_rate;
        double clean_price = 0.0;
        for (int i = 1; i <= periods; ++i) {
            clean_price += coupon / std::pow(1 + yield, i);
        }
        clean_price += face_value / std::pow(1 + yield, periods);
        return clean_price;
    }

    // Calculate dirty price of the bond
    double dirty_price(double clean_price, double accrued_interest) {
        return clean_price + accrued_interest;
    }

    // Calculate bond convexity
    double convexity(double face_value, double coupon_rate, double yield, int periods) {
        double coupon = face_value * coupon_rate;
        double convexity = 0.0;
        for (int i = 1; i <= periods; ++i) {
            convexity += (coupon * i * (i + 1)) / std::pow(1 + yield, i + 2);
        }
        convexity += (face_value * periods * (periods + 1)) / std::pow(1 + yield, periods + 2);
        return convexity;
    }

    // Calculate bond duration
    double duration(double face_value, double coupon_rate, double yield, int periods) {
        double coupon = face_value * coupon_rate;
        double duration = 0.0;
        for (int i = 1; i <= periods; ++i) {
            duration += (coupon * i) / std::pow(1 + yield, i);
        }
        duration += (face_value * periods) / std::pow(1 + yield, periods);
        return duration;
    }

    // Calculate modified duration of the bond
    double modified_duration(double duration, double yield) {
        return duration / (1 + yield);
    }

    // Calculate periodic cash flows of the bond
    std::vector<double> periodic_cash_flows(int periods, double face_value, double coupon_rate) {
        std::vector<double> cash_flows(periods + 1, face_value * coupon_rate);
        cash_flows[periods] += face_value;
        return cash_flows;
    }
};

PYBIND11_MODULE(BondAnalytics, m) {
    pybind11::class_<BondAnalytics>(m, "BondAnalytics")
        .def(pybind11::init<>())
        .def("clean_price", &BondAnalytics::clean_price, "Calculate clean price of the bond")
        .def("dirty_price", &BondAnalytics::dirty_price, "Calculate dirty price of the bond")
        .def("convexity", &BondAnalytics::convexity, "Calculate bond convexity")
        .def("duration", &BondAnalytics::duration, "Calculate bond duration")
        .def("modified_duration", &BondAnalytics::modified_duration, "Calculate modified duration of the bond")
        .def("periodic_cash_flows", &BondAnalytics::periodic_cash_flows, "Calculate periodic cash flows of the bond")
        ;
}

    
    // Calculate yield curve dynamics (simplified example using a flat yield curve)
    std::vector<double> yield_curve_dynamics(int periods, double initial_yield, double step) {
        std::vector<double> yield_curve(periods + 1, initial_yield);
        for (int i = 1; i <= periods; ++i) {
            yield_curve[i] = yield_curve[i - 1] + step;
        }
        return yield_curve;
    }

        .def("yield_curve_dynamics", &BondAnalytics::yield_curve_dynamics, "Calculate yield curve dynamics")
        ;
