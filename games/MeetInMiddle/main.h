#include <bits/stdc++.h>
using namespace std;

namespace MeetInMiddle {

const static int N = 5;

double pattern0(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[1] > inputs[2] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] + inputs[2] - inputs[3] - inputs[4];
}

string pattern0_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "+" << inputs[2] << "-" << inputs[3]
     << "-" << inputs[4];
  return ss.str();
}

double pattern1(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[2] > inputs[3] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] - inputs[2] - inputs[3] - inputs[4];
}

string pattern1_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "-" << inputs[2] << "-" << inputs[3]
     << "-" << inputs[4];
  return ss.str();
}

double pattern2(const vector<double>& inputs) {
  if (inputs[1] > inputs[2] || inputs[2] > inputs[3] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] - inputs[1] - inputs[2] - inputs[3] - inputs[4];
}

string pattern2_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-" << inputs[1] << "-" << inputs[2] << "-" << inputs[3]
     << "-" << inputs[4];
  return ss.str();
}

double pattern3(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[1] > inputs[2] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] + inputs[2] - inputs[3] * inputs[4];
}

string pattern3_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "+" << inputs[2] << "-" << inputs[3]
     << "*" << inputs[4];
  return ss.str();
}

double pattern4(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] - inputs[2] - inputs[3] * inputs[4];
}

string pattern4_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "-" << inputs[2] << "-" << inputs[3]
     << "*" << inputs[4];
  return ss.str();
}

double pattern5(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[1] > inputs[2]) {
    return NAN;
  }
  return inputs[0] + inputs[1] + inputs[2] - inputs[3] / inputs[4];
}

string pattern5_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "+" << inputs[2] << "-" << inputs[3]
     << "/" << inputs[4];
  return ss.str();
}

double pattern5_2(const vector<double>& inputs) {
  if (inputs[2] > inputs[3]) {
    return NAN;
  }
  return inputs[0] - inputs[1] + (inputs[2] + inputs[3]) / inputs[4];
}

string pattern5_2_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-" << inputs[1] << "+"
     << "(" << inputs[2] << "+" << inputs[3] << ")"
     << "/" << inputs[4];
  return ss.str();
}

double pattern5_3(const vector<double>& inputs) {
  return inputs[0] - inputs[1] + (inputs[2] - inputs[3]) / inputs[4];
}

string pattern5_3_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-" << inputs[1] << "+"
     << "(" << inputs[2] << "-" << inputs[3] << ")"
     << "/" << inputs[4];
  return ss.str();
}

double pattern6(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return inputs[0] + inputs[1] - inputs[2] - inputs[3] / inputs[4];
}

string pattern6_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "-" << inputs[2] << "-" << inputs[3]
     << "/" << inputs[4];
  return ss.str();
}

double pattern7(const vector<double>& inputs) {
  if (inputs[2] > inputs[3]) {
    return NAN;
  }
  return inputs[0] - inputs[1] + inputs[2] * inputs[3] / inputs[4];
}

string pattern7_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[2] << "*" << inputs[3] << "/" << inputs[4] << "+" << inputs[0]
     << "-" << inputs[1];
  return ss.str();
}

double pattern8(const vector<double>& inputs) {
  if (inputs[2] > inputs[3]) {
    return NAN;
  }
  return inputs[0] - inputs[1] - inputs[2] * inputs[3] / inputs[4];
}

string pattern8_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-" << inputs[1] << "-" << inputs[2] << "*" << inputs[3]
     << "/" << inputs[4];
  return ss.str();
}

double pattern9(const vector<double>& inputs) {
  if (inputs[1] > inputs[2] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] - inputs[1] * inputs[2] / (inputs[3] + inputs[4]);
}

string pattern9_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-" << inputs[1] << "*" << inputs[2] << "/(" << inputs[3]
     << "+" << inputs[4] << ")";
  return ss.str();
}

double pattern10(const vector<double>& inputs) {
  if (inputs[1] > inputs[2] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] * inputs[2] / (inputs[3] + inputs[4]);
}

string pattern10_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "*" << inputs[2] << "/(" << inputs[3]
     << "+" << inputs[4] << ")";
  return ss.str();
}

double pattern10_2(const vector<double>& inputs) {
  if (inputs[1] > inputs[2] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] * (inputs[3] + inputs[4]) / inputs[2];
}

string pattern10_2_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "*(" << inputs[3] << "+" << inputs[4]
     << ")/" << inputs[2];
  return ss.str();
}

double pattern11(const vector<double>& inputs) {
  if (inputs[1] > inputs[2]) {
    return NAN;
  }
  return inputs[0] + inputs[1] * inputs[2] / (inputs[3] - inputs[4]);
}

string pattern11_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "*" << inputs[2] << "/(" << inputs[3]
     << "-" << inputs[4] << ")";
  return ss.str();
}

double pattern12(const vector<double>& inputs) {
  return inputs[0] + inputs[1] / inputs[2] / (inputs[3] - inputs[4]);
}

string pattern12_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "/" << inputs[2] << "/(" << inputs[3]
     << "-" << inputs[4] << ")";
  return ss.str();
}

double pattern13(const vector<double>& inputs) {
  return inputs[0] * (inputs[1] - inputs[2]) + inputs[3] / inputs[4];
}

string pattern13_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "*(" << inputs[1] << "-" << inputs[2] << ") + "
     << inputs[3] << "/" << inputs[4];
  return ss.str();
}

double pattern14(const vector<double>& inputs) {
  return inputs[0] * (inputs[1] - inputs[2]) - inputs[3] / inputs[4];
}

string pattern14_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "*(" << inputs[1] << "-" << inputs[2] << ") - "
     << inputs[3] << "/" << inputs[4];
  return ss.str();
}

double pattern15(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return inputs[0] * inputs[1] / inputs[2] + inputs[3] / inputs[4];
}

string pattern15_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "*" << inputs[1] << "/" << inputs[2] << "+" << inputs[3]
     << "/" << inputs[4];
  return ss.str();
}

double pattern16(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return inputs[0] * inputs[1] / inputs[2] - inputs[3] / inputs[4];
}

string pattern16_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "*" << inputs[1] << "/" << inputs[2] << "-" << inputs[3]
     << "/" << inputs[4];
  return ss.str();
}

double pattern17(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] + inputs[2] / inputs[3] / inputs[4];
}

string pattern17_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "+" << inputs[2] << "/" << inputs[3]
     << "/" << inputs[4];
  return ss.str();
}

double pattern18(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] - inputs[2] / inputs[3] / inputs[4];
}

string pattern18_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "-" << inputs[2] << "/" << inputs[3]
     << "/" << inputs[4];
  return ss.str();
}

double pattern19(const vector<double>& inputs) {
  if (inputs[1] < inputs[2] || inputs[3] < inputs[4]) {
    return NAN;
  }
  return inputs[0] + (inputs[1] - inputs[2]) / (inputs[3] - inputs[4]);
}

string pattern19_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+"
     << "(" << inputs[1] << "-" << inputs[2] << ")/(" << inputs[3] << "-"
     << inputs[4] << ")";
  return ss.str();
}

double pattern19_2(const vector<double>& inputs) {
  if (inputs[1] < inputs[2] || inputs[3] < inputs[4]) {
    return NAN;
  }
  return inputs[0] - (inputs[1] - inputs[2]) / (inputs[3] - inputs[4]);
}

string pattern19_2_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-"
     << "(" << inputs[1] << "-" << inputs[2] << ")/(" << inputs[3] << "-"
     << inputs[4] << ")";
  return ss.str();
}

double pattern20(const vector<double>& inputs) {
  if (inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + (inputs[1] - inputs[2]) / (inputs[3] + inputs[4]);
}

string pattern20_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+"
     << "(" << inputs[1] << "-" << inputs[2] << ")/(" << inputs[3] << "+"
     << inputs[4] << ")";
  return ss.str();
}

double pattern21(const vector<double>& inputs) {
  if (inputs[1] > inputs[2] || inputs[2] > inputs[3]) {
    return NAN;
  }
  return inputs[0] + (inputs[1] + inputs[2] + inputs[3]) / inputs[4];
}

string pattern21_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+"
     << "(" << inputs[1] << "+" << inputs[2] << "+" << inputs[3] << ")"
     << "/" << inputs[4];
  return ss.str();
}

double pattern21_hard(const vector<double>& inputs) {
  if (inputs[1] > inputs[2]) {
    return NAN;
  }
  return inputs[0] + (inputs[1] + inputs[2] - inputs[3]) / inputs[4];
}

string pattern21_hard_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+"
     << "(" << inputs[1] << "+" << inputs[2] << "-" << inputs[3] << ")"
     << "/" << inputs[4];
  return ss.str();
}

double pattern22(const vector<double>& inputs) {
  if (inputs[1] > inputs[2] || inputs[2] > inputs[3]) {
    return NAN;
  }
  return inputs[0] - (inputs[1] + inputs[2] + inputs[3]) / inputs[4];
}

string pattern22_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-"
     << "(" << inputs[1] << "+" << inputs[2] << "+" << inputs[3] << ")"
     << "/" << inputs[4];
  return ss.str();
}

double pattern23(const vector<double>& inputs) {
  if (inputs[1] > inputs[2]) {
    return NAN;
  }
  return inputs[0] + (inputs[1] + inputs[2]) / (inputs[3] - inputs[4]);
}

string pattern23_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+"
     << "(" << inputs[1] << "+" << inputs[2] << ")/(" << inputs[3] << "-"
     << inputs[4] << ")";
  return ss.str();
}

double pattern24(const vector<double>& inputs) {
  if (inputs[1] > inputs[2] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + (inputs[1] + inputs[2]) / (inputs[3] + inputs[4]);
}

string pattern24_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+"
     << "(" << inputs[1] << "+" << inputs[2] << ")/(" << inputs[3] << "+"
     << inputs[4] << ")";
  return ss.str();
}

double pattern25(const vector<double>& inputs) {
  if (inputs[1] > inputs[2] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] - (inputs[1] + inputs[2]) / (inputs[3] + inputs[4]);
}

string pattern25_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-"
     << "(" << inputs[1] << "+" << inputs[2] << ")/(" << inputs[3] << "+"
     << inputs[4] << ")";
  return ss.str();
}

double pattern26(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[2] > inputs[3]) {
    return NAN;
  }
  return (inputs[0] * inputs[1] - inputs[2] - inputs[3]) / inputs[4];
}

string pattern26_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[0] << "*" << inputs[1] << "-" << inputs[2] << "-"
     << inputs[3] << ") / " << inputs[4];
  return ss.str();
}

double pattern27(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return (inputs[0] * inputs[1] - inputs[2] + inputs[3]) / inputs[4];
}

string pattern27_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[0] << "*" << inputs[1] << "-" << inputs[2] << "+"
     << inputs[3] << ") / " << inputs[4];
  return ss.str();
}

double pattern28(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[2] > inputs[3]) {
    return NAN;
  }
  return (inputs[0] * inputs[1] - inputs[2] * inputs[3]) / inputs[4];
}

string pattern28_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[0] << "*" << inputs[1] << "-" << inputs[2] << "*"
     << inputs[3] << ") / " << inputs[4];
  return ss.str();
}

double pattern29(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return (inputs[0] * inputs[1] - inputs[2] / inputs[3]) / inputs[4];
}

string pattern29_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[0] << "*" << inputs[1] << "-" << inputs[2] << "/"
     << inputs[3] << ") / " << inputs[4];
  return ss.str();
}

double pattern30(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return (inputs[0] * inputs[1] + inputs[2] / inputs[3]) / inputs[4];
}

string pattern30_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[0] << "*" << inputs[1] << "+" << inputs[2] << "/"
     << inputs[3] << ") / " << inputs[4];
  return ss.str();
}

double pattern31(const vector<double>& inputs) {
  if (inputs[2] > inputs[3] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] / (inputs[2] + inputs[3] + inputs[4]);
}

string pattern31_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "/(" << inputs[2] << "+" << inputs[3]
     << "+" << inputs[4] << ")";
  return ss.str();
}

double pattern32(const vector<double>& inputs) {
  if (inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] + inputs[1] / (inputs[2] - inputs[3] - inputs[4]);
}

string pattern32_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "+" << inputs[1] << "/(" << inputs[2] << "-" << inputs[3]
     << "-" << inputs[4] << ")";
  return ss.str();
}

double pattern33(const vector<double>& inputs) {
  if (inputs[2] > inputs[3] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] - inputs[1] / (inputs[2] + inputs[3] + inputs[4]);
}

string pattern33_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-" << inputs[1] << "/(" << inputs[2] << "+" << inputs[3]
     << "+" << inputs[4] << ")";
  return ss.str();
}

double pattern34(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return (inputs[0] + inputs[1]) * (inputs[2] - inputs[3]) / inputs[4];
}

string pattern34_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[0] << "+" << inputs[1] << ") * (" << inputs[2] << "-"
     << inputs[3] << ") / " << inputs[4];
  return ss.str();
}

double pattern35(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[2] > inputs[3]) {
    return NAN;
  }
  return (inputs[0] + inputs[1]) * (inputs[2] + inputs[3]) / inputs[4];
}

string pattern35_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[0] << "+" << inputs[1] << ") * (" << inputs[2] << "+"
     << inputs[3] << ") / " << inputs[4];
  return ss.str();
}

double pattern36(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return (inputs[0] + inputs[1]) * inputs[2] - inputs[3] * inputs[4];
}

string pattern36_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[0] << "+" << inputs[1] << ")*" << inputs[2] << " - "
     << inputs[3] << "*" << inputs[4];
  return ss.str();
}

double pattern37(const vector<double>& inputs) {
  if (inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] - inputs[1] + inputs[2] / (inputs[3] + inputs[4]);
}

string pattern37_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "-" << inputs[1] << "+" << inputs[2] << "/(" << inputs[3]
     << "+" << inputs[4] << ")";
  return ss.str();
}

double pattern38(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[2] > inputs[3]) {
    return NAN;
  }
  return inputs[0] * inputs[1] / (inputs[2] + inputs[3]) - inputs[4];
}

string pattern38_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "*" << inputs[1] << "/(" << inputs[2] << "+" << inputs[3]
     << ") - " << inputs[4];
  return ss.str();
}

double pattern39(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return inputs[0] * inputs[1] / (inputs[2] - inputs[3]) - inputs[4];
}

string pattern39_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << "*" << inputs[1] << "/(" << inputs[2] << "-" << inputs[3]
     << ") - " << inputs[4];
  return ss.str();
}

double impossible01(const vector<double>& inputs) {
  return inputs[0] / (inputs[1] / inputs[2] - inputs[3] / inputs[4]);
}

string impossible01_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " / (" << inputs[1] << " / " << inputs[2] << " - "
     << inputs[3] << " / " << inputs[4] << ")";
  return ss.str();
}

double impossible01_2(const vector<double>& inputs) {
  return inputs[0] * (inputs[1] / inputs[2] - inputs[3] / inputs[4]);
}

string impossible01_2_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " * (" << inputs[1] << " / " << inputs[2] << " - "
     << inputs[3] << " / " << inputs[4] << ")";
  return ss.str();
}

double impossible02(const vector<double>& inputs) {
  return inputs[0] / (inputs[1] / inputs[2] + inputs[3] / inputs[4]);
}

string impossible02_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " / (" << inputs[1] << " / " << inputs[2] << " + "
     << inputs[3] << " / " << inputs[4] << ")";
  return ss.str();
}

double impossible02_2(const vector<double>& inputs) {
  return inputs[0] * (inputs[1] / inputs[2] + inputs[3] / inputs[4]);
}

string impossible02_2_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " * (" << inputs[1] << " / " << inputs[2] << " + "
     << inputs[3] << " / " << inputs[4] << ")";
  return ss.str();
}

double impossible03(const vector<double>& inputs) {
  if (inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] / (inputs[1] - inputs[2] / (inputs[3] + inputs[4]));
}

string impossible03_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " / (" << inputs[1] << " - " << inputs[2] << " / ("
     << inputs[3] << " + " << inputs[4] << "))";
  return ss.str();
}

double impossible04(const vector<double>& inputs) {
  return inputs[0] / (inputs[1] - inputs[2] / (inputs[3] - inputs[4]));
}

string impossible04_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " / (" << inputs[1] << " - " << inputs[2] << " / ("
     << inputs[3] << " - " << inputs[4] << "))";
  return ss.str();
}

double impossible05(const vector<double>& inputs) {
  if (inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] / (inputs[1] - inputs[2] / inputs[3] / inputs[4]);
}

string impossible05_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " / (" << inputs[1] << " - " << inputs[2] << " / "
     << inputs[3] << " / " << inputs[4] << ")";
  return ss.str();
}

double impossible06(const vector<double>& inputs) {
  if (inputs[2] > inputs[3]) {
    return NAN;
  }
  return inputs[0] / (inputs[1] - inputs[2] * inputs[3] / inputs[4]);
}

string impossible06_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " / (" << inputs[1] << " - " << inputs[2] << " * "
     << inputs[3] << " / " << inputs[4] << ")";
  return ss.str();
}

double impossible07(const vector<double>& inputs) {
  if (inputs[1] > inputs[2]) {
    return NAN;
  }
  return (inputs[1] * inputs[2] + inputs[3] / inputs[4]) / inputs[0];
}

string impossible07_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[1] << " * " << inputs[2] << " + " << inputs[3] << " / "
     << inputs[4] << ") / " << inputs[0];
  return ss.str();
}

double impossible08(const vector<double>& inputs) {
  if (inputs[1] > inputs[2]) {
    return NAN;
  }
  return (inputs[1] * inputs[2] - inputs[3] / inputs[4]) / inputs[0];
}

string impossible08_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << "(" << inputs[1] << " * " << inputs[2] << " - " << inputs[3] << " / "
     << inputs[4] << ") / " << inputs[0];
  return ss.str();
}

double impossible09(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[2] > inputs[3] || inputs[3] > inputs[4]) {
    return NAN;
  }
  return inputs[0] * inputs[1] / (inputs[2] + inputs[3] + inputs[4]);
}

string impossible09_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " * " << inputs[1] << " / (" << inputs[2] << " + "
     << inputs[3] << " + " << inputs[4] << ")";
  return ss.str();
}

double impossible10(const vector<double>& inputs) {
  if (inputs[0] > inputs[1] || inputs[2] > inputs[3]) {
    return NAN;
  }
  return inputs[0] * inputs[1] / (inputs[2] + inputs[3] - inputs[4]);
}

string impossible10_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " * " << inputs[1] << " / (" << inputs[2] << " + "
     << inputs[3] << " - " << inputs[4] << ")";
  return ss.str();
}

double impossible11(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return inputs[0] * inputs[1] / (inputs[2] + inputs[3] / inputs[4]);
}

string impossible11_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " * " << inputs[1] << " / (" << inputs[2] << " + "
     << inputs[3] << "/" << inputs[4] << ")";
  return ss.str();
}

double impossible12(const vector<double>& inputs) {
  if (inputs[0] > inputs[1]) {
    return NAN;
  }
  return inputs[0] * inputs[1] / (inputs[2] - inputs[3] / inputs[4]);
}

string impossible12_str(const vector<double>& inputs) {
  ostringstream ss;
  ss << inputs[0] << " * " << inputs[1] << " / (" << inputs[2] << " - "
     << inputs[3] << "/" << inputs[4] << ")";
  return ss.str();
}

auto simple_patterns =
    vector<double (*)(const vector<double>&)>{pattern0, pattern1, pattern2};

auto simple_patterns_str = vector<string (*)(const vector<double>&)>{
    pattern0_str, pattern1_str, pattern2_str};

auto normal_patterns = vector<double (*)(const vector<double>&)>{
    pattern3,  pattern4,  pattern5,    pattern5_2, pattern5_3,
    pattern6,  pattern19, pattern19_2, pattern20,  pattern21,
    pattern22, pattern23, pattern24,   pattern25};

auto normal_patterns_str = vector<string (*)(const vector<double>&)>{
    pattern3_str,   pattern4_str,  pattern5_str,  pattern5_2_str,
    pattern5_3_str, pattern6_str,  pattern19_str, pattern19_2_str,
    pattern20_str,  pattern21_str, pattern22_str, pattern23_str,
    pattern24_str,  pattern25_str};

auto hard_patterns = vector<double (*)(const vector<double>&)>{
    pattern7,       pattern8,  pattern11, pattern12, pattern17, pattern18,
    pattern21_hard, pattern31, pattern32, pattern33, pattern37};

auto hard_patterns_str = vector<string (*)(const vector<double>&)>{
    pattern7_str,  pattern8_str,  pattern11_str,      pattern12_str,
    pattern17_str, pattern18_str, pattern21_hard_str, pattern31_str,
    pattern32_str, pattern33_str, pattern37_str};

auto crazy_patterns = vector<double (*)(const vector<double>&)>{
    pattern13, pattern14, pattern15,   pattern16, pattern26, pattern27,
    pattern28, pattern29, pattern30,   pattern34, pattern35, pattern36,
    pattern9,  pattern10, pattern10_2, pattern38, pattern39};

auto crazy_patterns_str = vector<string (*)(const vector<double>&)>{
    pattern13_str, pattern14_str, pattern15_str, pattern16_str, pattern26_str,
    pattern27_str, pattern28_str, pattern29_str, pattern30_str, pattern34_str,
    pattern35_str, pattern36_str, pattern9_str,  pattern10_str, pattern10_2_str,
    pattern38_str, pattern39_str};

auto impossible_patterns = vector<double (*)(const vector<double>&)>{
    impossible01, impossible01_2, impossible02, impossible02_2, impossible03,
    impossible04, impossible05,   impossible06, impossible07,   impossible08,
    impossible09, impossible10,   impossible11, impossible12};

auto impossible_patterns_str = vector<string (*)(const vector<double>&)>{
    impossible01_str, impossible01_2_str, impossible02_str, impossible02_2_str,
    impossible03_str, impossible04_str,   impossible05_str, impossible06_str,
    impossible07_str, impossible08_str,   impossible09_str, impossible10_str,
    impossible11_str, impossible12_str};

// check if t is integer or finite decimal
bool check(double t) {
  if (isinf(t) || isnan(t)) {
    return false;
  }
  double x = t * 1000000;
  return fabs(x - round(x)) < 1e-7;
}

void solve(vector<double> inputs) {
  if (inputs.size() != N) {
    cout << "Invalid input, size should be " << N << endl;
    return;
  }

  double T = 0;
  for (int i = 0; i < N; i++) {
    T += inputs[i];
  }
  T /= N;
  cout << "Average number is " << T << endl;

  double ans, ans_diff = 1e9;
  string ans_str = "";
  string prev_best = "";

  for (int i = 0; i < simple_patterns.size(); i++) {
    sort(inputs.begin(), inputs.end());
    do {
      double t = simple_patterns[i](inputs);
      if (check(t)) {
        double diff = fabs(T - t);
        if (diff <= ans_diff) {
          ans_diff = diff;
          ans = t;
          ans_str = simple_patterns_str[i](inputs);
          // cerr << ans_str << " = " << ans << "(diff = " << diff << ")" <<
          // endl;
        } else if (diff < ans_diff * 2 + 1) {
          auto desc = simple_patterns_str[i](inputs);
          // cerr << desc << " = " << t << "(diff = " << diff << ")" << endl;
        }
      }
    } while (next_permutation(inputs.begin(), inputs.end()));
  }

  prev_best = ans_str;
  cout << "Simple solution: " << ans_str << " = " << ans
       << " (diff = " << ans_diff << ")" << endl;

  for (int i = 0; i < normal_patterns.size(); i++) {
    sort(inputs.begin(), inputs.end());
    do {
      double t = normal_patterns[i](inputs);
      if (check(t)) {
        double diff = fabs(T - t);
        if (diff < ans_diff + 1e-9) {
          ans_diff = diff;
          ans = t;
          ans_str = normal_patterns_str[i](inputs);
          // cerr << ans_str << " = " << ans << "(diff = " << diff << ")" <<
          // endl;
        } else if (diff < ans_diff * 2 + 1) {
          auto desc = normal_patterns_str[i](inputs);
          // cerr << desc << " = " << t << "(diff = " << diff << ")" << endl;
        }
      }
    } while (next_permutation(inputs.begin(), inputs.end()));
  }

  if (ans_str != prev_best) {
    prev_best = ans_str;
    cout << "Normal solution: " << ans_str << " = " << ans
         << " (diff = " << ans_diff << ")" << endl;
  }

  for (int i = 0; i < hard_patterns.size(); i++) {
    sort(inputs.begin(), inputs.end());
    do {
      double t = hard_patterns[i](inputs);
      if (check(t)) {
        double diff = fabs(T - t);
        if (diff < ans_diff + 1e-9) {
          ans_diff = diff;
          ans = t;
          ans_str = hard_patterns_str[i](inputs);
          // cerr << ans_str << " = " << ans << "(diff = " << diff << ")" <<
          // endl;
        } else if (diff < ans_diff * 2 + 1) {
          auto desc = hard_patterns_str[i](inputs);
          // cerr << desc << " = " << t << "(diff = " << diff << ")" << endl;
        }
      }
    } while (next_permutation(inputs.begin(), inputs.end()));
  }

  if (ans_str != prev_best) {
    prev_best = ans_str;
    cout << "Hard solution: " << ans_str << " = " << ans
         << " (diff = " << ans_diff << ")" << endl;
  }

  for (int i = 0; i < crazy_patterns.size(); i++) {
    sort(inputs.begin(), inputs.end());
    do {
      double t = crazy_patterns[i](inputs);
      if (check(t)) {
        double diff = fabs(T - t);
        if (diff < ans_diff + 1e-9) {
          ans_diff = diff;
          ans = t;
          ans_str = crazy_patterns_str[i](inputs);
          // cerr << ans_str << " = " << ans << "(diff = " << diff << ")" <<
          // endl;
        } else if (diff < ans_diff * 2 + 1) {
          auto desc = crazy_patterns_str[i](inputs);
          // cerr << desc << " = " << t << "(diff = " << diff << ")" << endl;
        }
      }
    } while (next_permutation(inputs.begin(), inputs.end()));
  }

  if (ans_str != prev_best) {
    prev_best = ans_str;
    cout << "Crazy solution: " << ans_str << " = " << ans
         << " (diff = " << ans_diff << ")" << endl;
  }

  for (int i = 0; i < impossible_patterns.size(); i++) {
    sort(inputs.begin(), inputs.end());
    do {
      double t = impossible_patterns[i](inputs);
      if (check(t)) {
        double diff = fabs(T - t);
        if (diff < ans_diff + 1e-9) {
          ans_diff = diff;
          ans = t;
          ans_str = impossible_patterns_str[i](inputs);
          // cerr << ans_str << " = " << ans << "(diff = " << diff << ")" <<
          // endl;
        } else if (diff < ans_diff * 2 + 1) {
          auto desc = impossible_patterns_str[i](inputs);
          // cerr << desc << " = " << t << "(diff = " << diff << ")" << endl;
        }
      }
    } while (next_permutation(inputs.begin(), inputs.end()));
  }

  if (ans_str != prev_best) {
    prev_best = ans_str;
    cout << "Impossible solution: " << ans_str << " = " << ans
         << " (diff = " << ans_diff << ")" << endl;
  }
}

int startConsole() {
  while (true) {
    vector<double> inputs;
    for (int i = 0; i < N; i++) {
      double x;
      cin >> x;
      inputs.push_back(x);
    }
    solve(inputs);
  }
}
};  // namespace MeetInMiddle