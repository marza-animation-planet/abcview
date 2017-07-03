//-*****************************************************************************
//
// Copyright (c) 2014,
//  Sony Pictures Imageworks Inc. and
//  Industrial Light & Magic, a division of Lucasfilm Entertainment Company Ltd.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Industrial Light & Magic nor the names of
// its contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//-*****************************************************************************

#ifndef PyAbcOpenGL_Foundation_h_
#define PyAbcOpenGL_Foundation_h_

#include <Python.h>
#include <Alembic/AbcOpenGL/All.h>
#include <string>

// if Alembic::Util::shared_ptr resolves to boost::shared_ptr then we
// don't need this since it's defined elsewhere
#ifndef ALEMBIC_LIB_USES_BOOST
namespace boost
{

template<class T>
inline T * get_pointer( Alembic::Util::shared_ptr<T> const & p )
{
        return p.get();
}

} // namespace boost
#endif

#include <boost/python/detail/wrap_python.hpp>
#include <boost/python.hpp>

//-*****************************************************************************
inline void throwPythonException( const char* iMessage )
{
    PyErr_SetString( PyExc_RuntimeError, iMessage );
    throw boost::python::error_already_set();
}

inline void throwPythonKeyException( const char* iMessage )
{
    PyErr_SetString( PyExc_KeyError, iMessage );
    throw boost::python::error_already_set();
}

inline void throwPythonIndexException( const char* iMessage )
{
    PyErr_SetString( PyExc_IndexError, iMessage );
    throw boost::python::error_already_set();
}

#endif
