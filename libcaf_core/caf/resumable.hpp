/******************************************************************************
 *                       ____    _    _____                                   *
 *                      / ___|  / \  |  ___|    C++                           *
 *                     | |     / _ \ | |_       Actor                         *
 *                     | |___ / ___ \|  _|      Framework                     *
 *                      \____/_/   \_|_|                                      *
 *                                                                            *
 * Copyright (C) 2011 - 2014                                                  *
 * Dominik Charousset <dominik.charousset (at) haw-hamburg.de>                *
 *                                                                            *
 * Distributed under the terms and conditions of the BSD 3-Clause License or  *
 * (at your option) under the terms and conditions of the Boost Software      *
 * License 1.0. See accompanying files LICENSE and LICENCE_ALTERNATIVE.       *
 *                                                                            *
 * If you did not receive a copy of the license files, see                    *
 * http://opensource.org/licenses/BSD-3-Clause and                            *
 * http://www.boost.org/LICENSE_1_0.txt.                                      *
 ******************************************************************************/

#ifndef CAF_RESUMABLE_HPP
#define CAF_RESUMABLE_HPP

namespace caf {

class execution_unit;

/**
 * @brief A cooperatively executed task managed by one or more instances of
 *    {@link execution_unit}.
 */
class resumable {

 public:

  enum resume_result {
    resume_later,
    done,
    shutdown_execution_unit

  };

  resumable();

  virtual ~resumable();

  /**
   * @brief Initializes this object, e.g., by increasing the
   *    the reference count.
   */
  virtual void attach_to_scheduler() = 0;

  /**
   * @brief Uninitializes this object, e.g., by decrementing the
   *    the reference count.
   */
  virtual void detach_from_scheduler() = 0;

  /**
   * @brief Resume any pending computation until it is either finished
   *    or needs to be re-scheduled later.
   */
  virtual resume_result resume(execution_unit*) = 0;

 protected:

  bool m_hidden;

};

} // namespace caf

#endif // CAF_RESUMABLE_HPP