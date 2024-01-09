/**
 *@file geometry/distance.hpp
 *@author JeongHyeok Lim
 *@brief Point class declaration with 2-dimension
 *@version 1.0.0
 *@date 2023-01-07
 *@copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : JeongHyeok Lim

#ifndef Programmers__GEOMETRY__DISTANCE_HPP_
#define Programmers__GEOMETRY__DISTANCE_HPP_

namespace nodazi::geometry {
/**
 * @brief
 */
class Distance {
 public:
  /**
   * @brief
   */
  enum class Type {
    kKilometer = 0,
    kMeter = 1,
    kCentimeter = 2,
    kMillimeter = 3,
    kMicrometer = 4,
    kNanometer = 5
  };
  /**
   * @brief Construct a new Distance object
   */
  Distance() = default;

  /**
   * @brief Construct a new Distance object
   * @param input_value
   * @param input_type
   */
  explicit Distance(double input_value, Type input_type = Type ::kMeter);

  /**
   * @brief Construct a new Distance object
   * @param other
   */
  Distance(const Distance& other) = default;
  /**
   * @brief Construct a new Distance object
   */
  Distance(Distance&& other) noexcept = default;

  virtual ~Distance() = default;

 protected:
 private:
}
// 거리에 대한 정보를 저장하고 연산하는 클래스
// 추상화를 통해 구현을 숨기고, 사용자에게 필요한 기능만 제공한다.
// 사용자는 구현에 대해 알 필요가 없다.

// 특징
// 거리 type은 kilometer, meter, centimeter, millimeter, micrometer, nanometer
// 정확도는 1nm까지 허용한다.
// 1kilometer = 1,000meter
// 1meter = 100centimeter
// 1centimeter = 10millimeter
// 1millimeter = 1,000micrometer
// 1micrometer = 1,000nanometer
// 1kilometer = 1.0 * 10^3 meter = 1.0 * 10^6 centimeter = 1.0 * 10^7 millimeter
// = 1.0 * 10^9 micrometer = 1.0 * 10^12 nanometer

// 일반적으론 floating point type을 사용한다.
// distance 값은 int64_t로 관리한다.
// int64_t 최소값은 -9,223,372,036,854,775,808
// int64_t 최대값은 9,223,372,036,854,775,807
// 9,223,372,036,854,775,808 나노미터는 킬로미터로는 9,223,372.037km이다.

// double type은 연산을 하게 되면 불확실성이 생김
// floating point가 사칙연사에대해서 비용이 int type보다 훨씬 크다.
;
}  // namespace programmers::geometry

#endif