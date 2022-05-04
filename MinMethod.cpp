#include "h/MinMethod.h"
#include "h/ConjugateGradient.h"

std::vector<double> DichotomyM::result(class NeededFunction f, double left_border, double right_border, double eps) {
    double mid;
    double a = left_border;
    double b = right_border;

    while (b - a > eps) {
        mid = (b + a) / 2;

        double y1 = f.result(mid - D);
        double y2 = f.result(mid + D);


        if (y1 <= y2) {
            b = mid + D;
        } else if (y1 > y2) {
            a = mid - D;
        }
    }

    std::vector<double> result;
    result.push_back(a);
    result.push_back(b);

    return result;
}

std::vector<double> GoldenRatioM::result(class NeededFunction f, double left_border, double right_border, double eps) {
    double a = left_border, b = right_border;
    double x1 = b - (b - a) / GR;
    double x2 = a + (b - a) / GR;
    double y1 = f.result(x1);
    double y2 = f.result(x2);

    while (b - a > eps) {

        if (y1 <= y2) {
            b = x2;
            x2 = x1;
            y2 = y1;
            x1 = b - (b - a) / GR;
            y1 = f.result(x1);

        } else {
            a = x1;
            x1 = x2;
            y1 = y2;
            x2 = a + (b - a) / GR;
            y2 = f.result(x2);
        }
    }

    std::vector<double> result;
    result.push_back(a);
    result.push_back(b);

    return result;
}

std::vector<double> FibonacciM::result(class NeededFunction f, double left_border, double right_border, double eps) {
    double a = left_border, b = right_border;
    double n = (b - a) * 10;
    double x1 = a + (fibonacciNumberFunction(n) / fibonacciNumberFunction(n + 2)) * (b - a);
    double x2 = a + (fibonacciNumberFunction(n + 1) / fibonacciNumberFunction(n + 2)) * (b - a);
    double y1 = f.result(x1);
    double y2 = f.result(x2);
    while (b - a > eps) {
        if (y1 <= y2) {
            b = x2;
            x2 = x1;
            y2 = y1;
            x1 = a + (fibonacciNumberFunction(n) / fibonacciNumberFunction(n + 2)) * (b - a);
            y1 = f.result(x1);
        } else {
            a = x1;
            x1 = x2;
            y1 = y2;
            x2 = a + (fibonacciNumberFunction(n + 1) / fibonacciNumberFunction(n + 2)) * (b - a);
            y2 = f.result(x2);
        }
    }

    std::vector<double> result;
    result.push_back(a);
    result.push_back(b);

    return result;
}

std::vector<double> ParabolaM::result(class NeededFunction func, double left_border, double right_border, double eps) {
    double a = left_border, b = right_border;
    while (b - a > eps) {
        double y1 = func.result(a);
        double c = (b + a) / 2;
        double y2 = func.result(c);
        double y3 = func.result(b);
        double u = std::abs(c - (pow((c - a), 2) * ((y2 - y3) - pow((c - b), 2) * (y3 - y1)) /
                                 (2 * ((c - a) * (y2 - y3) - (c - b) * (y2 - y1)))));
        double f = func.result(u);
        if (c < u) {
            if (y2 < f) {
                b = u;
            } else {
                a = c;
            }
        } else {
            if (y2 < f) {
                a = u;
            } else {
                b = c;
            }
        }
    }

    std::vector<double> result;
    result.push_back(a);
    result.push_back(b);

    return result;
}

std::vector<double> BrentM::result(class NeededFunction f, double left_border, double right_border, double eps) {
    double a = left_border;
    double b = right_border;
    double w = b - (b - a) / GR;
    double x = b - (b - a) / GR;
    double v = b - (b - a) / GR;
    double u;
    double yw = f.result(w);
    double yx = f.result(x);
    double yv = f.result(v);

    double d = b - a;
    double e = b - a;

    while (b - a > eps) {

        double g = e;
        e = d;

        double uTemp;
        if (x != w && w != v && x != v && yx != yw && yw != yv && yx != yv) {
            uTemp = std::abs(v - (pow((v - w), 2) * ((yx - yv) - pow((v - x), 2) * (yv - yw)) /
                                  (2 * ((v - w) * (yx - yv) - (v - x) * (yx - yw)))));

            if (uTemp >= a + eps && a <= b - eps && std::abs(uTemp - x) < g / 2) {
                u = uTemp;
                d = std::abs(u - x);
            } else {
                if (x < (b + a) / 2) {
                    u = x + GR_REV * (b - x);
                    d = b - x;
                } else {
                    u = x - GR_REV * (x - a);
                    d = x - a;
                }
            }
        } else {
            if (x < (b + a) / 2) {
                u = x + GR_REV * (b - x);
                d = b - x;
            } else {
                u = x - GR_REV * (x - a);
                d = x - a;
            }
        }

        double yu = f.result(u);

        if (yu <= yx) {
            if (u >= x) {
                a = x;
            } else {
                b = x;
            }
            v = w;
            w = x;
            x = u;
            yv = yw;
            yw = yx;
            yx = yu;
        } else {
            if (u >= x) {
                b = u;
            } else {
                a = u;
            }

            if (yu <= yw || w == x) {
                v = w;
                w = u;
                yv = yw;
                yw = yu;
            } else if (yu <= yv || v == x || v == w) {
                v = u;
                yv = yu;
            }
        }
    }

    std::vector<double> result;
    result.push_back(a);
    result.push_back(b);

    return result;
}

