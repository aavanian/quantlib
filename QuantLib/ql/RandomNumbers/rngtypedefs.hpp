

/*
 Copyright (C) 2002, 2003 Ferdinando Ametrano
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email ferdinando@ametrano.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/
/*! \file rngtypedefs.hpp
    \brief Default choices for template instantiations

    \fullpath
    ql/RandomNumbers/%rngtypedefs.hpp
*/

// $Id$

#ifndef quantlib_rng_typedefs_h
#define quantlib_rng_typedefs_h

#include <ql/RandomNumbers/lecuyeruniformrng.hpp>
#include <ql/RandomNumbers/knuthuniformrng.hpp>

#include <ql/RandomNumbers/boxmullergaussianrng.hpp>
#include <ql/RandomNumbers/centrallimitgaussianrng.hpp>
#include <ql/RandomNumbers/inversecumgaussianrng.hpp>

#include <ql/RandomNumbers/randomarraygenerator.hpp>

#include <ql/RandomNumbers/randomsequencegenerator.hpp>
#include <ql/RandomNumbers/haltonrsg.hpp>

#include <ql/RandomNumbers/inversecumgaussianrsg.hpp>

namespace QuantLib {

    namespace RandomNumbers {

/************* Uniform number generators *************/

        // no low discrepancy, since they are sequence generators.

        // Lecuyer and Knuth uniform number generators, plus:

        //! default choice for uniform random number generator.
        typedef LecuyerUniformRng UniformRandomGenerator;
        // should be Marsenne Twister as soon as it is available in QuantLib


/************* Gaussian number generators *************/

        // no low discrepancy, since they are sequence generators.

        // Gaussian random number generators based on
        // Lecuyer uniform random number generator
        // 1) Central Limit
        typedef CLGaussianRng<LecuyerUniformRng>
			CentralLimitLecuyerGaussianRng;
        // 2) Box Muller
        typedef BoxMullerGaussianRng<LecuyerUniformRng>
			BoxMullerLecuyerGaussianRng;
        // 3) Moro
        typedef ICGaussianRng<LecuyerUniformRng,
            QuantLib::Math::MoroInverseCumulativeNormal>
			MoroInvCumulativeLecuyerGaussianRng;
        // 4) Acklam (recommended)
        typedef ICGaussianRng<LecuyerUniformRng,
            QuantLib::Math::InverseCumulativeNormal>
			InvCumulativeLecuyerGaussianRng;
        
        // Gaussian random number generators based on
        // Knuth uniform random number generator
        // 1) Central Limit
        typedef CLGaussianRng<KnuthUniformRng>
			CentralLimitKnuthGaussianRng;
        // 2) Box Muller
        typedef BoxMullerGaussianRng<KnuthUniformRng>
			BoxMullerKnuthGaussianRng;
        // 3) Moro
        typedef ICGaussianRng<KnuthUniformRng,
            QuantLib::Math::MoroInverseCumulativeNormal>
			MoroInvCumulativeKnuthGaussianRng;
        // 4) Acklam (recommended)
        typedef ICGaussianRng<KnuthUniformRng,
            QuantLib::Math::InverseCumulativeNormal>
			InvCumulativeKnuthGaussianRng;

        //! default choice for Gaussian random number generator.
        typedef BoxMullerGaussianRng<UniformRandomGenerator>
			GaussianRandomGenerator;
        // it should be the following typedef, which use
        // a better uniform->guassian algo, but
        // the change will happen when UniformRandomGenerator
        // will be the Marsenne Twister, so that we have to updated
        // the calculated values in the test suite only once
        //typedef ICGaussianRng<UniformRandomGenerator,
        //    QuantLib::Math::InverseCumulativeNormal>
		//	GaussianRandomGenerator;

        //! default choice for Gaussian array generator.
        typedef RandomArrayGenerator<GaussianRandomGenerator>
			GaussianArrayGenerator;


/************* Uniform sequence generators *************/

        // all low discrepancy sequence generators (HaltonRsg
        // for the time being), plus:
        typedef RandomSequenceGenerator<LecuyerUniformRng> LecuyerUniformRsg;
        typedef RandomSequenceGenerator<KnuthUniformRng> KnuthUniformRsg;

        //! default choice for uniform random sequence generator.
        typedef LecuyerUniformRsg UniformRandomSequenceGenerator;
        // should be Marsenne Twister as soon as it is available in QuantLib

        //! default choice for uniform low discrepancy sequence generator
        typedef HaltonRsg UniformLowDiscrepancySequenceGenerator;
        // should be Sobol as soon as it is available in QuantLib



/************* Gaussian sequence generators *************/

        // Gaussian random sequence generators based on
        // Lecuyer uniform random sequence generator
        // 1) Moro
        typedef ICGaussianRsg<LecuyerUniformRsg,
            QuantLib::Math::MoroInverseCumulativeNormal>
			MoroInvCumulativeLecuyerGaussianRsg;
        // 2) Acklam
        typedef ICGaussianRsg<LecuyerUniformRsg,
            QuantLib::Math::InverseCumulativeNormal>
			InvCumulativeLecuyerGaussianRsg;

        // Gaussian random sequence generators based on
        // Knuth uniform random sequence generator
        // 1) Moro
        typedef ICGaussianRsg<KnuthUniformRsg,
            QuantLib::Math::MoroInverseCumulativeNormal>
			MoroInvCumulativeKnuthGaussianRsg;
        // 2) Acklam
        typedef ICGaussianRsg<KnuthUniformRsg,
            QuantLib::Math::InverseCumulativeNormal>
			InvCumulativeKnuthGaussianRsg;

        // Gaussian low discrepancy sequence generators based on
        // Halton uniform low discrepancy sequence generator
        // 1) Moro
        typedef ICGaussianRsg<HaltonRsg,
            QuantLib::Math::MoroInverseCumulativeNormal>
			MoroInvCumulativeHaltonGaussianRsg;
        // 2) Acklam
        typedef ICGaussianRsg<HaltonRsg,
            QuantLib::Math::InverseCumulativeNormal>
			InvCumulativeHaltonGaussianRsg;

        //! default choice for gaussian random sequence generator.
        typedef InvCumulativeLecuyerGaussianRsg GaussianRandomSequenceGenerator;
        // should be Marsenne Twister as soon as it is available in QuantLib

        //! default choice for gaussian low discrepancy sequence generator
        typedef InvCumulativeHaltonGaussianRsg GaussianLowDiscrepancySequenceGenerator;
        // should be Sobol as soon as it is available in QuantLib


    }

}


#endif
