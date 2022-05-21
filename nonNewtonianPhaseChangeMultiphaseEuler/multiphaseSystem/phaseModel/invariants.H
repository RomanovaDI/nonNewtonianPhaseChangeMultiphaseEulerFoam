/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2013 OpenFOAM Foundation
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

#include "GeometricTensorField.H"
#include "tensorFieldField.H"
#include "GeometricSymmTensorField.H"
#include "symmTensorFieldField.H"
//#include "invariants.H"

#define TEMPLATE template<template<class> class PatchField, class GeoMesh>
#include "GeometricFieldFunctionsM.C"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//- Return the 1st invariant of a SymmTensor
template<class Cmpt, template<class> class PatchField, class GeoMesh>
void Foam::invariantI
(
    GeometricField<Cmpt, PatchField, GeoMesh>& result,
    const Foam::tmp<GeometricField<Foam::SymmTensor<Cmpt>, PatchField, GeoMesh>>& st
)
{
    auto input = st.ref().primitiveField();
	forAll (input, i)
		result[i] = invariantI(input[i]);
}


//- Return the 2nd invariant of a SymmTensor
template<class Cmpt, template<class> class PatchField, class GeoMesh>
void Foam::invariantII
(
    GeometricField<Cmpt, PatchField, GeoMesh>& result,
    const Foam::tmp<GeometricField<Foam::SymmTensor<Cmpt>, PatchField, GeoMesh>>& st
)
{
    auto input = st.ref().primitiveField();
	forAll (input, i)
		result[i] = invariantII(input[i]);
}


//- Return the 3rd invariant of a SymmTensor
template<class Cmpt, template<class> class PatchField, class GeoMesh>
void Foam::invariantIII
(
    GeometricField<Cmpt, PatchField, GeoMesh>& result,
    const Foam::tmp<GeometricField<Foam::SymmTensor<Cmpt>, PatchField, GeoMesh>>& st
)
{
    auto input = st.ref().primitiveField();
	forAll (input, i)
		result[i] = invariantIII(input[i]);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "undefFieldFunctionsM.H"

// ************************************************************************* //
