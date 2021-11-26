// *****************************************************************************
//
// © Copyright 2020, Septentrio NV/SA.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//    1. Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//    2. Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//    3. Neither the name of the copyright holder nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// *****************************************************************************

// *****************************************************************************
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:

// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// *****************************************************************************

#ifndef GPGGA_HPP
#define GPGGA_HPP

// ROSaic includes
#include <septentrio_gnss_driver/parsers/parser_base_class.hpp>
#include <septentrio_gnss_driver/parsers/string_utilities.h>
// Boost and ROS includes
#include <boost/make_shared.hpp>
#include <septentrio_gnss_driver/Gpgga.h>

/**
 * @file gpgga.hpp
 * @brief Derived class for parsing GGA messages
 * @date 17/08/20
 */

/**
 * @class GpggaParser
 * @brief Derived class for parsing GGA messages
 * @date 13/08/20
 */
class GpggaParser : public BaseParser<septentrio_gnss_driver::GpggaPtr>
{
public:
    /**
     * @brief Constructor of the class GpggaParser
     */
    GpggaParser() :
        BaseParser<septentrio_gnss_driver::GpggaPtr>(), was_last_gpgga_valid_(false)
    {
    }

    /**
     * @brief Returns the ASCII message ID, here "$GPGGA"
     * @return The message ID
     */
    const std::string getMessageID() const override;

    /**
     * @brief Parses one GGA message
     * @param[in] sentence The GGA message to be parsed
     * @return A ROS message pointer of ROS type septentrio_gnss_driver::GpggaPtr
     */
    septentrio_gnss_driver::GpggaPtr
    parseASCII(const NMEASentence& sentence, const std::string& frame_id, bool use_gnss_time) noexcept(false) override;

    /**
     * @brief Tells us whether the last GGA message was valid or not
     * @return True if last GGA message was valid, false if not
     */
    bool wasLastGPGGAValid() const;

    /**
     * @brief Declares the string MESSAGE_ID
     */
    static const std::string MESSAGE_ID;

private:
    /**
     * @brief Declares a boolean representing whether or not the last GPGGA message
     * was valid
     */
    bool was_last_gpgga_valid_;
};

#endif // GPGGA_HPP
