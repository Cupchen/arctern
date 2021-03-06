/*
 * Copyright (C) 2019-2020 Zilliz. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <string>
#include <utility>
#include <vector>

#include "render/utils/vega/vega_scatter_plot/vega_scatter_plot.h"

namespace arctern {
namespace render {

class VegaWeightedPointmap : public VegaScatterPlot {
 public:
  VegaWeightedPointmap() = default;

  explicit VegaWeightedPointmap(const std::string& json);

  // TODO: add Build() api to build a vega json string.
  // std::string Build() final;

  const PointParams point_params() const { return point_params_; }

  const std::pair<double, double>& color_bound() const { return color_bound_; }

  const std::pair<double, double>& size_bound() const { return size_bound_; }

  const double& opacity() const { return opacity_; }

  const bool& is_multiple_color() const { return is_multiple_color_; }

  const bool& is_multiple_point_size() const { return is_multiple_point_size_; }

  const std::vector<Color>& color_gradient() { return color_gradient_; }

 private:
  // vega json to vega struct
  void Parse(const std::string& json) final;

 private:
  PointParams point_params_;
  std::pair<double, double> color_bound_;
  std::pair<double, double> size_bound_;
  double opacity_;
  bool is_multiple_color_;
  bool is_multiple_point_size_;
  std::vector<Color> color_gradient_;
};

}  // namespace render
}  // namespace arctern
