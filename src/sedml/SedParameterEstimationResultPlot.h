/**
 * @file SedParameterEstimationResultPlot.h
 * @brief Definition of the SedParameterEstimationResultPlot class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedParameterEstimationResultPlot
 * @sbmlbrief{sedml} TODO:Definition of the SedParameterEstimationResultPlot
 * class.
 */


#ifndef SedParameterEstimationResultPlot_H__
#define SedParameterEstimationResultPlot_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedPlot.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedParameterEstimationResultPlot : public SedPlot
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mName;
  std::string mTaskRef;

  /** @endcond */

public:

  /**
   * Creates a new SedParameterEstimationResultPlot using the given SEDML Level
   * and @ p version values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedParameterEstimationResultPlot.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedParameterEstimationResultPlot.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedParameterEstimationResultPlot(unsigned int level = SEDML_DEFAULT_LEVEL,
                                   unsigned int version =
                                     SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedParameterEstimationResultPlot using the given
   * SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedParameterEstimationResultPlot(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedParameterEstimationResultPlot.
   *
   * @param orig the SedParameterEstimationResultPlot instance to copy.
   */
  SedParameterEstimationResultPlot(const SedParameterEstimationResultPlot&
    orig);


  /**
   * Assignment operator for SedParameterEstimationResultPlot.
   *
   * @param rhs the SedParameterEstimationResultPlot object whose values are to
   * be used as the basis of the assignment.
   */
  SedParameterEstimationResultPlot& operator=(const
    SedParameterEstimationResultPlot& rhs);


  /**
   * Creates and returns a deep copy of this SedParameterEstimationResultPlot
   * object.
   *
   * @return a (deep) copy of this SedParameterEstimationResultPlot object.
   */
  virtual SedParameterEstimationResultPlot* clone() const;


  /**
   * Destructor for SedParameterEstimationResultPlot.
   */
  virtual ~SedParameterEstimationResultPlot();


  /**
   * Returns the value of the "id" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @return the value of the "id" attribute of this
   * SedParameterEstimationResultPlot as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @return the value of the "name" attribute of this
   * SedParameterEstimationResultPlot as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Returns the value of the "taskRef" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @return the value of the "taskRef" attribute of this
   * SedParameterEstimationResultPlot as a string.
   */
  const std::string& getTaskRef() const;


  /**
   * Predicate returning @c true if this SedParameterEstimationResultPlot's
   * "id" attribute is set.
   *
   * @return @c true if this SedParameterEstimationResultPlot's "id" attribute
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this SedParameterEstimationResultPlot's
   * "name" attribute is set.
   *
   * @return @c true if this SedParameterEstimationResultPlot's "name"
   * attribute has been set, otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Predicate returning @c true if this SedParameterEstimationResultPlot's
   * "taskRef" attribute is set.
   *
   * @return @c true if this SedParameterEstimationResultPlot's "taskRef"
   * attribute has been set, otherwise @c false is returned.
   */
  bool isSetTaskRef() const;


  /**
   * Sets the value of the "id" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * Calling this function with @p id = @c NULL or an empty string is
   * equivalent to calling unsetId().
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "name" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p name = @c NULL or an empty string is
   * equivalent to calling unsetName().
   */
  virtual int setName(const std::string& name);


  /**
   * Sets the value of the "taskRef" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param taskRef std::string& value of the "taskRef" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTaskRef(const std::string& taskRef);


  /**
   * Unsets the value of the "id" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "name" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetName();


  /**
   * Unsets the value of the "taskRef" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTaskRef();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedParameterEstimationResultPlot
   * object.
   *
   * For SedParameterEstimationResultPlot, the XML element name is always
   * @c "parameterEstimationResultPlot".
   *
   * @return the name of this element, i.e. @c "parameterEstimationResultPlot".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedParameterEstimationResultPlot
   * object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   * @sedmlconstant{SEDML_PARAMETERESTIMATIONRESULTPLOT, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedParameterEstimationResultPlot object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedParameterEstimationResultPlot have been set, otherwise @c false is
   * returned.
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Accepts the given SedVisitor
   */
  virtual bool accept(SedVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the parent SedDocument
   */
  virtual void setSedDocument(SedDocument* d);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Predicate returning @c true if this SedParameterEstimationResultPlot's
   * attribute "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedParameterEstimationResultPlot's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this
   * SedParameterEstimationResultPlot.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedParameterEstimationResultPlot_t using the given SEDML Level
 * and @ p version values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedParameterEstimationResultPlot_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedParameterEstimationResultPlot_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
SedParameterEstimationResultPlot_t *
SedParameterEstimationResultPlot_create(unsigned int level,
                                        unsigned int version);


/**
 * Creates and returns a deep copy of this SedParameterEstimationResultPlot_t
 * object.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @return a (deep) copy of this SedParameterEstimationResultPlot_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
SedParameterEstimationResultPlot_t*
SedParameterEstimationResultPlot_clone(const
  SedParameterEstimationResultPlot_t* sperp);


/**
 * Frees this SedParameterEstimationResultPlot_t object.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
void
SedParameterEstimationResultPlot_free(SedParameterEstimationResultPlot_t*
  sperp);


/**
 * Returns the value of the "id" attribute of this
 * SedParameterEstimationResultPlot_t.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure whose id is
 * sought.
 *
 * @return the value of the "id" attribute of this
 * SedParameterEstimationResultPlot_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
char *
SedParameterEstimationResultPlot_getId(const SedParameterEstimationResultPlot_t
  * sperp);


/**
 * Returns the value of the "name" attribute of this
 * SedParameterEstimationResultPlot_t.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure whose name is
 * sought.
 *
 * @return the value of the "name" attribute of this
 * SedParameterEstimationResultPlot_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
char *
SedParameterEstimationResultPlot_getName(const
  SedParameterEstimationResultPlot_t * sperp);


/**
 * Returns the value of the "taskRef" attribute of this
 * SedParameterEstimationResultPlot_t.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure whose taskRef
 * is sought.
 *
 * @return the value of the "taskRef" attribute of this
 * SedParameterEstimationResultPlot_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
char *
SedParameterEstimationResultPlot_getTaskRef(const
  SedParameterEstimationResultPlot_t * sperp);


/**
 * Predicate returning @c 1 (true) if this SedParameterEstimationResultPlot_t's
 * "id" attribute is set.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @return @c 1 (true) if this SedParameterEstimationResultPlot_t's "id"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_isSetId(const
  SedParameterEstimationResultPlot_t * sperp);


/**
 * Predicate returning @c 1 (true) if this SedParameterEstimationResultPlot_t's
 * "name" attribute is set.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @return @c 1 (true) if this SedParameterEstimationResultPlot_t's "name"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_isSetName(const
  SedParameterEstimationResultPlot_t * sperp);


/**
 * Predicate returning @c 1 (true) if this SedParameterEstimationResultPlot_t's
 * "taskRef" attribute is set.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @return @c 1 (true) if this SedParameterEstimationResultPlot_t's "taskRef"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_isSetTaskRef(const
  SedParameterEstimationResultPlot_t * sperp);


/**
 * Sets the value of the "id" attribute of this
 * SedParameterEstimationResultPlot_t.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling SedParameterEstimationResultPlot_unsetId().
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_setId(
                                       SedParameterEstimationResultPlot_t *
                                         sperp,
                                       const char * id);


/**
 * Sets the value of the "name" attribute of this
 * SedParameterEstimationResultPlot_t.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedParameterEstimationResultPlot_unsetName().
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_setName(
                                         SedParameterEstimationResultPlot_t *
                                           sperp,
                                         const char * name);


/**
 * Sets the value of the "taskRef" attribute of this
 * SedParameterEstimationResultPlot_t.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @param taskRef const char * value of the "taskRef" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_setTaskRef(
                                            SedParameterEstimationResultPlot_t
                                              * sperp,
                                            const char * taskRef);


/**
 * Unsets the value of the "id" attribute of this
 * SedParameterEstimationResultPlot_t.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_unsetId(SedParameterEstimationResultPlot_t *
  sperp);


/**
 * Unsets the value of the "name" attribute of this
 * SedParameterEstimationResultPlot_t.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_unsetName(SedParameterEstimationResultPlot_t *
  sperp);


/**
 * Unsets the value of the "taskRef" attribute of this
 * SedParameterEstimationResultPlot_t.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_unsetTaskRef(SedParameterEstimationResultPlot_t
  * sperp);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedParameterEstimationResultPlot_t object have been set.
 *
 * @param sperp the SedParameterEstimationResultPlot_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedParameterEstimationResultPlot_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 * @memberof SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_hasRequiredAttributes(const
  SedParameterEstimationResultPlot_t * sperp);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedParameterEstimationResultPlot_H__ */


