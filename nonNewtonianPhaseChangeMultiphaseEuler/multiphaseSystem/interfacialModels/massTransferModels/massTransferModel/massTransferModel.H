/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2015 OpenFOAM Foundation
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
    Foam::massTransferModel

Description

SourceFiles
    massTransferModel.C

\*---------------------------------------------------------------------------*/

#ifndef massTransferModel_H
#define massTransferModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "phaseModel.H"
#include "runTimeSelectionTables.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class massTransferModel Declaration
\*---------------------------------------------------------------------------*/

class massTransferModel
{
protected:

    // Protected Data

        const dictionary& interfaceDict_;
        const phaseModel& phase1_;
        const phaseModel& phase2_;
		dictionary massTransferModelCoeffs_;
//        dimensionedScalar residualPhaseFraction_;
//        dimensionedScalar residualSlip_;

public:

    //- Runtime type information
    TypeName("massTransferModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            massTransferModel,
            dictionary,
            (
                const dictionary& interfaceDict,
                const phaseModel& phase1,
                const phaseModel& phase2
            ),
            (interfaceDict, phase1, phase2)
        );


    // Constructors

        massTransferModel
        (
		 	const word& type,
            const dictionary& dict,
            const phaseModel& phase1,
            const phaseModel& phase2
        );


    //- Destructor
    virtual ~massTransferModel() = default;


    // Selectors

        static autoPtr<massTransferModel> New
        (
            const dictionary& dict,
            const phaseModel& phase1,
            const phaseModel& phase2
        );


    // Member Functions

        const phaseModel& phase1() const
        {
            return phase1_;
        }

        const phaseModel& phase2() const
        {
            return phase2_;
        }

        //const dimensionedScalar& residualPhaseFraction() const
        //{
        //    return residualPhaseFraction_;
        //}

        //const dimensionedScalar& residualSlip() const
        //{
        //    return residualSlip_;
        //}

        //- The drag function K used in the momentum eq.
        //    ddt(alpha1*U1) + ... = ... + alpha1*K1 + alpha2*K2
        //    ddt(alpha2*U2) + ... = ... + alpha1*K1 + alpha2*K2
        // ********************************** NB! *****************************
        // for numerical reasons alpha1 and alpha2 has been
        // extracted from the dragFunction K,
        // so you MUST divide K by alpha1*alpha2 when implementing the drag
        // function
        // ********************************** NB! *****************************
        virtual tmp<volScalarField> K() const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
