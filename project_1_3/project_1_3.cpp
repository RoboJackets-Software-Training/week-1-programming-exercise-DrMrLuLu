#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);
  

  // TODO write your code here
  // =========== START =========

  std::cout << "x: {";
  for(int i = 0; i < x.size(); i++) {
    if(i != 0) {
      std::cout << ", ";
    }
    std::cout << x[i];
  }
  std::cout << "}" << std::endl;

  std::cout << "w: {";
  for(int i = 0; i < w.size(); i++) {
    if(i != 0) {
      std::cout << ", ";
    }
    std::cout << w[i];
  }
  std::cout << "}" << std::endl;


  int offset = (w.size()-1)/2;

  for(int i = 0; i < x.size(); i++) {
    int numb = 0;
    for(int j = 0; j < w.size(); j++) {
      if(!pack_with_zeros && i - offset + j < 0) {
        numb += x[0] * w[j];
      } else if(!pack_with_zeros && i - offset + j >= x.size()) {
        numb += x[x.size()-1] * w[j];
      } else {
        numb += x[i - offset + j]*w[j];
      }
    }
    y.push_back(numb);
  }

  std::cout << "y: {";
  for(int i = 0; i < y.size(); i++) {
    if(i != 0) {
      std::cout << ", ";
    }
    std::cout << y[i];
  }
  std::cout << "}" << std::endl;

  // =========== END ===========

  return 0;
}

