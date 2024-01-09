/**
 *@file geometry/point2d.cpp
 *@author Lim Jeong Hyeok
 *@brief Point class developments with 2-dimension
 *@version 1.0.0
 *@date 2024-01-09
 *@copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : Lim Jeong Hyeok

#include "geometry/point2d.hpp"

#include <cmath>
#include <limits>
#include <stdexcept>

#include "gtest/gtest.h"

namespace programmers::geometry {
Point2D::Point2D(double input_x, double input_y) : x_(input_x), y_(input_y){};

auto Point2D::CalculateDistance(const Point2D& target) const -> double {
  return Point2D::CalculateDistance(*this, target);
}

auto Point2D::CalculateDistance(const Point2D& lhs,
                                const Point2D& rhs) -> double {
  return std::sqrt(std::pow((lhs.x_ - rhs.x_), 2) +
                   std::pow(lhs.y_ - rhs.y_, 2));
}

auto Point2D::GetX() const -> double { return x_; }

auto Point2D::GetY() const -> double { return y_; }

auto Point2D::SetX(double input_x) -> void { x_ = input_x; }

auto Point2D::SetY(double input_y) -> void { y_ = input_y; }

auto Point2D::operator+(const Point2D& other) const -> Point2D {
  Point2D plusPoint2D;
  plusPoint2D.x_ = x_ + other.x_;
  plusPoint2D.y_ = y_ + other.y_;
  return plusPoint2D;
}

auto Point2D::operator-(const Point2D& other) const -> Point2D {
  Point2D minusPoint2D;
  minusPoint2D.x_ = x_ - other.x_;
  minusPoint2D.y_ = y_ - other.y_;
  return minusPoint2D;
}
auto Point2D::operator+=(const Point2D& other) -> void {
  x_ += other.x_;
  y_ += other.y_;
}

auto Point2D::operator-=(const Point2D& other) -> void {
  x_ -= other.x_;
  y_ -= other.y_;
}

auto Point2D::operator*(double scalar) const -> Point2D {
  Point2D multipliedPoint2D;
  multipliedPoint2D.x_ = x_ * scalar;
  multipliedPoint2D.y_ = y_ * scalar;
  return multipliedPoint2D;
}

auto Point2D::operator/(double scalar) const -> Point2D {
  Point2D dividedPoint2D;
  dividedPoint2D.x_ = x_ / scalar;
  dividedPoint2D.y_ = y_ / scalar;
  return dividedPoint2D;
}

auto Point2D::operator==(const Point2D& other) const -> bool {
  return ((x_ == other.x_) & (y_ == other.y_));
}

auto Point2D::operator!=(const Point2D& other) const -> bool {
  return !Point2D::operator==(other);
}

}  // namespace programmers::geometry