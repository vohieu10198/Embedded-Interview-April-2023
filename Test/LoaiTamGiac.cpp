#include <gtest/gtest.h>
#include <algorithm>


enum LoaiTamGiac {
    TamGiacKhongTonTai,
    TamGiacDeu,
    TamGiacCan,
    TamGiacVuong,
    TamGiacThuong
};

LoaiTamGiac XacDinhLoaiTamGiac(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return TamGiacKhongTonTai;
    }

    if (a == b && b == c) {
        return TamGiacDeu;
    }

    if (a == b || b == c || c == a) {
        return TamGiacCan;
    }

    double maxSide = std::max(a, std::max(b, c));
    double sumSquares = a * a + b * b + c * c;

    if (2 * maxSide * maxSide == sumSquares) {
        return TamGiacVuong;
    }

    return TamGiacThuong;
}


TEST(XacDinhLoaiTamGiac, TamGiacKhongTonTai1){
    double canh_1 = 0;
    double canh_2 = 1;
    double canh_3 = 2;

    LoaiTamGiac tamGiac = XacDinhLoaiTamGiac(canh_1, canh_2, canh_3);
    EXPECT_EQ(tamGiac, TamGiacKhongTonTai);

}

TEST(XacDinhLoaiTamGiac, TamGiacKhongTonTai2){
    double canh_1 = 3;
    double canh_2 = -1;
    double canh_3 = 2;

    LoaiTamGiac tamGiac = XacDinhLoaiTamGiac(canh_1, canh_2, canh_3);
    EXPECT_EQ(tamGiac, TamGiacKhongTonTai);

}

TEST(XacDinhLoaiTamGiac, TamGiacKhongTonTai3){
    double canh_1 = 3;
    double canh_2 = 4;
    double canh_3 = -5;

    LoaiTamGiac tamGiac = XacDinhLoaiTamGiac(canh_1, canh_2, canh_3);
    EXPECT_EQ(tamGiac, TamGiacKhongTonTai);

}

TEST(XacDinhLoaiTamGiac, TamGiacDeu){
    double canh_1 = 3;
    double canh_2 = 3;
    double canh_3 = 3;

    LoaiTamGiac tamGiac = XacDinhLoaiTamGiac(canh_1, canh_2, canh_3);
    EXPECT_EQ(tamGiac, TamGiacDeu);

}

TEST(XacDinhLoaiTamGiac, TamGiacCan1){
    double canh_1 = 3;
    double canh_2 = 3;
    double canh_3 = 5;

    LoaiTamGiac tamGiac = XacDinhLoaiTamGiac(canh_1, canh_2, canh_3);
    EXPECT_EQ(tamGiac, TamGiacCan);

}

TEST(XacDinhLoaiTamGiac, TamGiacCan2){
    double canh_1 = 3;
    double canh_2 = 5;
    double canh_3 = 5;

    LoaiTamGiac tamGiac = XacDinhLoaiTamGiac(canh_1, canh_2, canh_3);
    EXPECT_EQ(tamGiac, TamGiacCan);

}

TEST(XacDinhLoaiTamGiac, TamGiacCan3){
    double canh_1 = 3;
    double canh_2 = 5;
    double canh_3 = 3;

    LoaiTamGiac tamGiac = XacDinhLoaiTamGiac(canh_1, canh_2, canh_3);
    EXPECT_EQ(tamGiac, TamGiacCan);

}

TEST(XacDinhLoaiTamGiac, TamGiacVuong){
    double canh_1 = 3;
    double canh_2 = 4;
    double canh_3 = 5;

    LoaiTamGiac tamGiac = XacDinhLoaiTamGiac(canh_1, canh_2, canh_3);
    EXPECT_EQ(tamGiac, TamGiacVuong);

}

TEST(XacDinhLoaiTamGiac, TamGiacThuong){
    double canh_1 = 3;
    double canh_2 = 6;
    double canh_3 = 7;

    LoaiTamGiac tamGiac = XacDinhLoaiTamGiac(canh_1, canh_2, canh_3);
    EXPECT_EQ(tamGiac, TamGiacThuong);

}
