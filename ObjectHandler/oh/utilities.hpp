
/*
 Copyright (C) 2004, 2005 Eric Ehlers

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file
    \brief ObjectHandler utilities
*/

#ifndef oh_utilities_hpp
#define oh_utilities_hpp

#include <oh/objecthandler.hpp>

//! ObjectHandler factory function makeObject
/*! Construct an object of class \a CLASS with handle \a HANDLE
    and argument stack \a ARGUMENTS
*/
#define OH_MAKE_OBJECT( CLASS, HANDLE, ARGUMENTS ) \
    ObjHandler::Factory< CLASS >::makeObject( HANDLE, ARGUMENTS )
//! ObjectHandler function retrieveObject
/*! Retrieve Object of class \a CLASS with handle \a HANDLE.
*/
#define OH_GET_OBJECT( CLASS, HANDLE ) \
    boost::dynamic_pointer_cast< CLASS > \
    (ObjHandler::ObjectHandler::instance().retrieveObject( HANDLE ))
//! ObjectHandler function deleteObject
/*! delete Object with handle \a HANDLE.
*/
#define OH_DELETE_OBJECT( HANDLE ) \
    ObjHandler::ObjectHandler::instance().deleteObject( HANDLE )
//! ObjectHandler function deleteAllObjects
/*! delete all Objects in the repository.
*/
#define OH_DELETE_ALL_OBJECTS() \
    ObjHandler::ObjectHandler::instance().deleteAllObjects()
//! Object function popArgument
/*! Pop an argument of type \a CLASS from argument stack \a ARGUMENTS.
*/
#define OH_POP_ARGUMENT( CLASS, ARGUMENTS ) \
    ObjHandler::Arguments< CLASS >::popArgument( ARGUMENTS )
//! Object function getReference
/*! Retrieve a reference to underlying Object of class \a CLASS
    with handle \a HANDLE.
*/
#define OH_GET_REFERENCE( CLASS, OBJECT ) \
    boost::static_pointer_cast< CLASS > ( OBJECT->getReference() )

namespace ObjHandler {

    /** \name Logging framework
     *  These functions wrap calls to the Logger class
        simplifying the syntax for the client application
        and alleviating the need for the client application
        to #include log4cxx headers.
    */
    //@{
    //! Wrapper for function Logger::instance().setLogFile().
    /*! Specify name of log file.
    */
    void OH_LOGFILE(const std::string &logFileName,
                const int &logLevel = 4);
    //! Wrapper for function Logger::instance().logMessage()
    /*! Write a message to the log file.
    */
    void OH_LOG_MESSAGE(
            const std::string &message,
            const int &level = 4);
    //! Wrapper for function Logger::instance().setLogLevel().
    /*! Set logging threshold.
    */
    void OH_LOG_LEVEL(const int &logLevel);
    //! Wrapper for function Logger::instance().setConsole().
    /*! Fork log messages to stdout.
    */
    void OH_CONSOLE(const int &console = 0,
                const int &logLevel = 4);
    //! Write Object with given handle to log file.
    /*! Writes a warning message to log file
        if no object is found with given handle.
    */
    void OH_LOG_OBJECT(const std::string &handle);
    //! Write all Objects to log file.
    /*! Takes no action if ObjectHandler
        repository is empty.
    */
    void OH_LOG_ALL_OBJECTS();
    //@}

}

#endif

