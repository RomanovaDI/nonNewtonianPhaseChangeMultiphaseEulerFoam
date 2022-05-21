/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011 OpenFOAM Foundation
    Copyright (C) 2019-2021 OpenCFD Ltd.
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

\*---------------------------------------------------------------------------*/

#include "massTransferModel.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(massTransferModel, 0);
    defineRunTimeSelectionTable(massTransferModel, dictionary);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::massTransferModel::massTransferModel
(
 	const word& type,
    const dictionary& dict,
    const phaseModel& phase1,
    const phaseModel& phase2
)
:
    interfaceDict_(dict),
    phase1_(phase1),
    phase2_(phase2),
	massTransferModelCoeffs_(interfaceDict_.optionalSubDict(type+"Coeffs"))
    //residualPhaseFraction_("residualPhaseFraction", dimless, dict),
    //residualSlip_("residualSlip", dimVelocity, dict)
{}


// * * * * * * * * * * * * * * * * Selectors * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::massTransferModel> Foam::massTransferModel::New
(
    const dictionary& dict,
    const phaseModel& phase1,
    const phaseModel& phase2
)
{
    const word modelType(dict.get<word>("type"));

    Info<< "Selecting massTransferModel for phase "
        << phase1.name()
        << ": "
        << modelType << endl;

    auto* ctorPtr = dictionaryConstructorTable(modelType);

    if (!ctorPtr)
    {
        FatalIOErrorInLookup
        (
            dict,
            "massTransferModel",
            modelType,
            *dictionaryConstructorTablePtr_
        ) << exit(FatalIOError);
    }

    return ctorPtr(dict, phase1, phase2);
}


// ************************************************************************* //
