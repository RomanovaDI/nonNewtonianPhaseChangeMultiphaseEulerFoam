/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011 OpenFOAM Foundation
    Copyright (C) 2020 OpenCFD Ltd.
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::massTransferModels::entrainment

Description
	Phase that is reduced should be placed first like (soil, water) in
	entrainment process

SourceFiles
    entrainment.C

\*---------------------------------------------------------------------------*/

#ifndef entrainment_H
#define entrainment_H

#include "massTransferModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace massTransferModels
{

/*---------------------------------------------------------------------------*\
                           Class entrainment Declaration
\*---------------------------------------------------------------------------*/

class entrainment
:
    public massTransferModel
{
    // Private data
	dimensionedScalar entrCoeff_;

public:

    //- Runtime type information
    TypeName("entrainment");


    // Constructors

        //- Construct from components
        entrainment
        (
            const dictionary& interfaceDict,
            const phaseModel& phase1,
            const phaseModel& phase2
        );


    //- Destructor
    virtual ~entrainment() = default;


    // Member Functions

        tmp<volScalarField> K() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace massTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
