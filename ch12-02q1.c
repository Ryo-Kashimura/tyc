#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    bool inEcoMode : 1;
    uint8_t shiftPosition: 3;
    bool parkingBrakePulled: 1;
    uint16_t engineSpeed: 14;
    int8_t blinkerPosition: 2;
    uint8_t switched: 2;
} Car;

void printCar(Car car) {
    char ecoMode[2][4] = {"ON", "OFF"};
    char shiftPosition[5][2] = {"P", "R", "N", "D", "L"};
    char parkingBrake[2][4] = {"ON", "OFF"};
    char blinkerPosition[3][4] = {"左", "中", "右"};
    char engineSwitch[4][16] = {"停止", "電源ON", "エンジンON", "スターター"};
    printf("    エコモード    : %s\n", ecoMode[!car.inEcoMode]);
    printf("    シフト位置    : %s\n", shiftPosition[car.shiftPosition]);
    printf("    サイドブレーキ: %s\n", parkingBrake[!car.parkingBrakePulled]);
    printf("    エンジン回転数: %-4i\n", car.engineSpeed);
    printf("    ウィンカー位置: %s\n", blinkerPosition[car.blinkerPosition + 1]);
    printf("    スイッチ      : %s\n", engineSwitch[car.switched]);
}

int main() {
    Car cars[3] = {
        {.inEcoMode = 0, .shiftPosition = 0, .parkingBrakePulled = 1, .engineSpeed = 0, .blinkerPosition = 0, .switched = 0},
        {.inEcoMode = 1, .shiftPosition = 3, .parkingBrakePulled = 0, .engineSpeed = 1500, .blinkerPosition = 0, .switched = 2},
        {.inEcoMode = 0, .shiftPosition = 2, .parkingBrakePulled = 0, .engineSpeed = 800, .blinkerPosition = -1, .switched = 2}
    };
    for (int i = 0; i < 3; i++) {
        printf("car #%i:\n", i + 1);
        printCar(cars[i]);
    }
    return 0;
}
