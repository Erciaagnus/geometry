/**
 *@file point2d.hpp
 *@author JeongHyeok Lim (henricus0973@korea.ac.kr)
 *@brief Point class declaration with 2-dimention
 *@version 0.1
 *@date 2024-01-07
 *
 *@copyright Copyright (c) 2024 Programmers All Rights Reserved.
 *
 */

//@copyright Copyright (c) 2024 Programmers All Rights Reserved.
// Authors: JeongHyeok Lim

// header Guard
#ifndef Programmers_GEOMETRY_POINT_2_HPP_
#define Programmers_GEOMETRY_POINT_2_HPP_

namespace programmers::geometry {

/**
 * @brief Point class with 2-dimention
 */
class Point2D {
public:
  /**
   * @brief Construct a new Point 2 D object
   * @param x Double type x coordinate value
   * @param y Double type y coordinate value
   */
  Point2D() = default;
  /**
   * @brief Construct a new Point 2 D object
   * @param x Double type x coordinate value
   * @param y Double type y coordinate value
   */
  Point2D(double x, double y);
  /**
   * @brief Copy construct a new Point 2 D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(const Point2D &other) = default;
  /**
   * @brief Move construct a new Point 2 D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(Point2D &&other) noexcept = default;

  /**
   * @brief Destroy the Point 2 D object
   *
   */
  virtual ~Point2D() = default;
  /**
   * @brief Copy assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  // Point2D new_one = old_one;
  // new_one.GetX();
  // old_one.GetX();

  auto operator=(const Point2D &other) -> Point2D & = default;
  /**
   * @brief Move assignment operator
   * @param other other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  // new_one.GetX();
  // old_one.GetX(); impossible xxxxxxxxxx
  auto operator=(Point2D &&other) -> Point2D & = default;
  /**
   * @brief Calculate distance between this point and target point
   * @param target Other Point2D object to calculate distance
   * @return double Euclidean distance between this point and target point
   */

  auto CalculateDistance(const Point2D &target) const -> double;
  /**
   * @brief Calculate distance between lhs point and rhs point
   * @param lhs Left hand side Point2D object
   * @param rhs Right hand side Point2D object
   * @return double Euclidean distance between lhs point and rhs point
   */
  [[nodiscard]] static auto CalculateDistance(const Point2D &lhs,
                                              const Point2D &rhs) -> double;
  /**
   * @brief Set x coordinate value
   * @param x Double type input x coordinate value
   */
  void SetX(double x);
  /**
   * @brief Set y coordinate value
   * @param y Double type input y coordinate value
   */
  void SetY(double y);

  /**
   * @brief Get x coordinate value of this point
   * @return double x coordinate value of this point
   */

  [[nodiscard]] auto GetX() const -> double;
  /**
   * @brief Get y coordinate value of this point
   * @return double y coordinate value of this point
   */

  [[nodiscard]] auto GetY() const -> double;

  /**
   * @brief Over loaded addition operator for Point2D
   * @param other The point2D object to be added
   * @return The result of the addition as a new Point2D object
   */
  auto operator+(const Point2D &other) const -> Point2D;

  /**
   * @brief Overloaded subtraction operator for Point2D.
   *
   * This operator performs element-wise subtraction of two Point2D objects.
   *
   * @param other The Point2D object to be subtracted.
   * @return The result of the subtraction as a new Point2D object.
   */

  auto operator-(const Point2D &other) const -> Point2D;

  /**
   * @brief Overloaded addition assignment operator for Point2D.
   *
   * This operator performs element-wise addition and assigns the result to the
   * current Point2D object.
   *
   * @param other The Point2D object to be added.
   * @return A reference to the modified Point2D object.
   */

  auto operator+=(const Point2D &other) const -> Point2D;

  /**
   * @brief Overloaded subtraction assignment operator for Point2D.
   *
   * This operator performs element-wise subtraction and assigns the result to
   * the current Point2D object.
   *
   * @param other The Point2D object to be subtracted.
   * @return A reference to the modified Point2D object.
   */

  auto operator-=(const Point2D &other) const -> Point2D;
  /**
   * @brief Overloaded equality operator for Point2D.
   *
   * This operator checks if two Point2D objects are equal element-wise.
   *
   * @param other The Point2D object to be compared for equality.
   * @return True if the objects are equal, false otherwise.
   */
  auto operator==(const Point2D &other) const -> Point2D;
  /**
   * @brief Overloaded inequality operator for Point2D.
   *
   * This operator checks if two Point2D objects are not equal element-wise.
   *
   * @param other The Point2D object to be compared for inequality.
   * @return True if the objects are not equal, false otherwise.
   */
  auto operator!=(const Point2D &other) const -> Point2D;

protected:
private:
  double x_{0.0}; ///< x coordinate
  double y_{0.0}; ///< y coordinate
};

} // namespace programmers::geometry

#endif // Programmers_GEOMETRY_POINT_2_HPP_
