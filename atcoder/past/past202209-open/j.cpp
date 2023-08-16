#include "template.hpp"

const double PI = acos(-1);

int main() {
    double h, w, r;
    cin >> h >> w >> r;
    if (h > w)
        swap(h, w);

    double area;
    if (2 * r < h) {
        area = PI * r * r;
    } else if (2 * r < w) {
        double theta = acos((h / 2) / r);
        double sector = r * r * theta;
        double triangle = sqrt(r * r - h * h / 4) * h / 2;
        area = PI * r * r - 2 * sector + 2 * triangle;
    } else if (2 * r < sqrt(h * h + w * w)) {
        double theta1 = acos((h / 2) / r);
        double sector1 = r * r * theta1;
        double triangle1 = sqrt(r * r - h * h / 4) * h / 2;
        double theta2 = acos((w / 2) / r);
        double sector2 = r * r * theta2;
        double triangle2 = sqrt(r * r - w * w / 4) * w / 2;
        area = PI * r * r - 2 * sector1 + 2 * triangle1 - 2 * sector2 + 2 * triangle2;
    } else {
        area = h * w;
    }
    cout << area / (h * w) << endl;

    return 0;
}
