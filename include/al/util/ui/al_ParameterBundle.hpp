#ifndef AL_PARAMETERBUNDLE_H
#define AL_PARAMETERBUNDLE_H

/*	Allocore --
	Multimedia / virtual environment application class library

	Copyright (C) 2009. AlloSphere Research Group, Media Arts & Technology, UCSB.
	Copyright (C) 2012-2015. The Regents of the University of California.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

		Redistributions of source code must retain the above copyright notice,
		this list of conditions and the following disclaimer.

		Redistributions in binary form must reproduce the above copyright
		notice, this list of conditions and the following disclaimer in the
		documentation and/or other materials provided with the distribution.

		Neither the name of the University of California nor the names of its
		contributors may be used to endorse or promote products derived from
		this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.

	File description:
    Class to group parameters to simplify multiple instantiation
	File author(s):
	Andrés Cabrera mantaraya36@gmail.com
*/

#include <string>
#include <vector>

#include "al/util/ui/al_Parameter.hpp"

namespace al
{

class ParameterBundle
{
public:
    /**
     * @brief ParameterBundle
     * @param prefix prefix to add to OSC path
     *
     * If no prefix is given, each new ParameterBundle gets a different consecutive
     * number with the prefix "bundle_" e.g. bundle_0, bundle_1, etc.
     */
    ParameterBundle(std::string prefix = "", bool appendCounter = true);

    /**
     * @brief get the prefix for this bundle
     * @return the prefix string
     */
    std::string bundlePrefix() const;

    int bundleIndex() const;

    void addParameter(ParameterMeta *parameter);

    ParameterBundle &operator <<(ParameterMeta *parameter);
    ParameterBundle &operator <<(ParameterMeta &parameter);


private:
    static int mBundleCounter;
    int mBundleIndex = -1;
    std::string mBundlePrefix;

    std::vector<ParameterMeta *> mParameters;

};

}


#endif // AL_PARAMETERBUNDLE_H