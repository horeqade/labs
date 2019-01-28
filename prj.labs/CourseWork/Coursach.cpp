#include <stdio.h>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
#include <pybind11/eval.h>
#include <pybind11/embed.h>
#include <string>

namespace py = pybind11;

class generator {
 public:
  generator() {}
  generator(std::string json_path, std::string weights_path,
            bool abs_path_json = false, bool abs_path_weights = false) {
    py::object json;
    if (abs_path_json) {
      json = open(json_path);
    } else {
      json = open(default_path + json_path);
    }
    model = model_from_json(json.attr("read")().cast<std::string>());
    if (abs_path_weights) {
      model.attr("load_weights")(weights_path);
    } else {
      model.attr("load_weights")(default_path + weights_path);
    }
    std::cout << json.attr("read")().cast<std::string>();
  }
  void make_pics(int pic_num = 1) {
    py::object dims = util.attr("mkarr")(pic_num, 100);
    py::object z = np_random.attr("normal")(0, 1, dims);
    py::object pics_arr = model.attr("predict")(z);
    util.attr("save")(pics_arr, default_path);
  }

 private:
  py::object util = py::module::import("utilities");
  py::object model_from_json =
      py::module::import("keras.models").attr("model_from_json");
  py::object np_random = py::module::import("numpy.random");
  py::object cv2 = py::module::import("cv2");
  py::object model;
  std::string default_path{
      "D:\\programming\\proga\\Portnov_N_S\\prj.labs\\CourseWork\\"};
  std::string json_path{""};
  std::string weights_path{""};
  py::object open(std::string path) {
    return py::module::import("builtins").attr("open")(path, "r");
  }
};

int main() {
  Py_SetPythonHome(L"D:/programming/Anaconda1/envs/Coursach");
  py::scoped_interpreter python;

  py::object sys_path = py::module::import("sys").attr("path");
  sys_path.attr("append")(
      "D:\\programming\\proga\\Portnov_N_S\\prj.labs\\CourseWork\\");
  py::object util = py::module::import("utilities");
  py::object model_from_json =
      py::module::import("keras.models").attr("model_from_json");
  py::object np_random = py::module::import("numpy.random");
  py::object cv2 = py::module::import("cv2");

  generator gen("23.12 gen_model.json", "23.12 1380_epoch gen_weights.h5");
  gen.make_pics(4);

  return 0;
}