/**
 * @file SedAdjustableParameter.cpp
 * @brief Implementation of the SedAdjustableParameter class.
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
 */
#include <sedml/SedAdjustableParameter.h>
#include <sedml/SedListOfAdjustableParameters.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedAdjustableParameter using the given SEDML Level and @ p
 * version values.
 */
SedAdjustableParameter::SedAdjustableParameter(unsigned int level,
                                               unsigned int version)
  : SedBase(level, version)
  , mBounds (NULL)
  , mExperimentRefs (level, version)
  , mModelReference ("")
  , mTarget ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedAdjustableParameter using the given SedNamespaces object @p
 * sedmlns.
 */
SedAdjustableParameter::SedAdjustableParameter(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mBounds (NULL)
  , mExperimentRefs (sedmlns)
  , mModelReference ("")
  , mTarget ("")
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedAdjustableParameter.
 */
SedAdjustableParameter::SedAdjustableParameter(const SedAdjustableParameter&
  orig)
  : SedBase( orig )
  , mBounds ( NULL )
  , mExperimentRefs ( orig.mExperimentRefs )
  , mModelReference ( orig.mModelReference )
  , mTarget ( orig.mTarget )
{
  if (orig.mBounds != NULL)
  {
    mBounds = orig.mBounds->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedAdjustableParameter.
 */
SedAdjustableParameter&
SedAdjustableParameter::operator=(const SedAdjustableParameter& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mExperimentRefs = rhs.mExperimentRefs;
    mModelReference = rhs.mModelReference;
    mTarget = rhs.mTarget;
    delete mBounds;
    if (rhs.mBounds != NULL)
    {
      mBounds = rhs.mBounds->clone();
    }
    else
    {
      mBounds = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAdjustableParameter object.
 */
SedAdjustableParameter*
SedAdjustableParameter::clone() const
{
  return new SedAdjustableParameter(*this);
}


/*
 * Destructor for SedAdjustableParameter.
 */
SedAdjustableParameter::~SedAdjustableParameter()
{
  delete mBounds;
  mBounds = NULL;
}


/*
 * Returns the value of the "modelReference" attribute of this
 * SedAdjustableParameter.
 */
const std::string&
SedAdjustableParameter::getModelReference() const
{
  return mModelReference;
}


/*
 * Returns the value of the "target" attribute of this SedAdjustableParameter.
 */
const std::string&
SedAdjustableParameter::getTarget() const
{
  return mTarget;
}


/*
 * Predicate returning @c true if this SedAdjustableParameter's
 * "modelReference" attribute is set.
 */
bool
SedAdjustableParameter::isSetModelReference() const
{
  return (mModelReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedAdjustableParameter's "target"
 * attribute is set.
 */
bool
SedAdjustableParameter::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Sets the value of the "modelReference" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setModelReference(const std::string& modelReference)
{
  if (!(SyntaxChecker::isValidInternalSId(modelReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mModelReference = modelReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "target" attribute of this SedAdjustableParameter.
 */
int
SedAdjustableParameter::setTarget(const std::string& target)
{
  mTarget = target;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "modelReference" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::unsetModelReference()
{
  mModelReference.erase();

  if (mModelReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "target" attribute of this SedAdjustableParameter.
 */
int
SedAdjustableParameter::unsetTarget()
{
  mTarget.erase();

  if (mTarget.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "bounds" element of this SedAdjustableParameter.
 */
const SedBounds*
SedAdjustableParameter::getBounds() const
{
  return mBounds;
}


/*
 * Returns the value of the "bounds" element of this SedAdjustableParameter.
 */
SedBounds*
SedAdjustableParameter::getBounds()
{
  return mBounds;
}


/*
 * Predicate returning @c true if this SedAdjustableParameter's "bounds"
 * element is set.
 */
bool
SedAdjustableParameter::isSetBounds() const
{
  return (mBounds != NULL);
}


/*
 * Sets the value of the "bounds" element of this SedAdjustableParameter.
 */
int
SedAdjustableParameter::setBounds(const SedBounds* bounds)
{
  if (mBounds == bounds)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (bounds == NULL)
  {
    delete mBounds;
    mBounds = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mBounds;
    mBounds = (bounds != NULL) ? bounds->clone() : NULL;
    if (mBounds != NULL)
    {
      mBounds->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedBounds object, adds it to this SedAdjustableParameter
 * object and returns the SedBounds object created.
 */
SedBounds*
SedAdjustableParameter::createBounds()
{
  if (mBounds != NULL)
  {
    delete mBounds;
  }

  mBounds = new SedBounds(getSedNamespaces());

  connectToChild();

  return mBounds;
}


/*
 * Unsets the value of the "bounds" element of this SedAdjustableParameter.
 */
int
SedAdjustableParameter::unsetBounds()
{
  delete mBounds;
  mBounds = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfExperimentRefs from this SedAdjustableParameter.
 */
const SedListOfExperimentRefs*
SedAdjustableParameter::getListOfExperimentRefs() const
{
  return &mExperimentRefs;
}


/*
 * Returns the SedListOfExperimentRefs from this SedAdjustableParameter.
 */
SedListOfExperimentRefs*
SedAdjustableParameter::getListOfExperimentRefs()
{
  return &mExperimentRefs;
}


/*
 * Get a SedExperimentRef from the SedAdjustableParameter.
 */
SedExperimentRef*
SedAdjustableParameter::getExperimentRef(unsigned int n)
{
  return mExperimentRefs.get(n);
}


/*
 * Get a SedExperimentRef from the SedAdjustableParameter.
 */
const SedExperimentRef*
SedAdjustableParameter::getExperimentRef(unsigned int n) const
{
  return mExperimentRefs.get(n);
}


/*
 * Get a SedExperimentRef from the SedAdjustableParameter based on the
 * ExperimentId to which it refers.
 */
const SedExperimentRef*
SedAdjustableParameter::getExperimentRefByExperimentId(const std::string& sid)
  const
{
  return mExperimentRefs.getByExperimentId(sid);
}


/*
 * Get a SedExperimentRef from the SedAdjustableParameter based on the
 * ExperimentId to which it refers.
 */
SedExperimentRef*
SedAdjustableParameter::getExperimentRefByExperimentId(const std::string& sid)
{
  return mExperimentRefs.getByExperimentId(sid);
}


/*
 * Adds a copy of the given SedExperimentRef to this SedAdjustableParameter.
 */
int
SedAdjustableParameter::addExperimentRef(const SedExperimentRef* ser)
{
  if (ser == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ser->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ser->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ser->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ser)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mExperimentRefs.append(ser);
  }
}


/*
 * Get the number of SedExperimentRef objects in this SedAdjustableParameter.
 */
unsigned int
SedAdjustableParameter::getNumExperimentRefs() const
{
  return mExperimentRefs.size();
}


/*
 * Creates a new SedExperimentRef object, adds it to this
 * SedAdjustableParameter object and returns the SedExperimentRef object
 * created.
 */
SedExperimentRef*
SedAdjustableParameter::createExperimentRef()
{
  SedExperimentRef* ser = NULL;

  try
  {
    ser = new SedExperimentRef(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ser != NULL)
  {
    mExperimentRefs.appendAndOwn(ser);
  }

  return ser;
}


/*
 * Removes the nth SedExperimentRef from this SedAdjustableParameter and
 * returns a pointer to it.
 */
SedExperimentRef*
SedAdjustableParameter::removeExperimentRef(unsigned int n)
{
  return mExperimentRefs.remove(n);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedAdjustableParameter::renameSIdRefs(const std::string& oldid,
                                      const std::string& newid)
{
  if (isSetModelReference() && mModelReference == oldid)
  {
    setModelReference(newid);
  }
}


/*
 * Returns the XML element name of this SedAdjustableParameter object.
 */
const std::string&
SedAdjustableParameter::getElementName() const
{
  static const string name = "adjustableParameter";
  return name;
}


/*
 * Returns the libSEDML type code for this SedAdjustableParameter object.
 */
int
SedAdjustableParameter::getTypeCode() const
{
  return SEDML_ADJUSTABLE_PARAMETER;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAdjustableParameter object have been set.
 */
bool
SedAdjustableParameter::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedAdjustableParameter object have been set.
 */
bool
SedAdjustableParameter::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetBounds() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedAdjustableParameter::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (isSetBounds() == true)
  {
    mBounds->write(stream);
  }

  if (getNumExperimentRefs() > 0)
  {
    mExperimentRefs.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedAdjustableParameter::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAdjustableParameter::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  if (mBounds != NULL)
  {
    mBounds->setSedDocument(d);
  }

  mExperimentRefs.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedAdjustableParameter::connectToChild()
{
  SedBase::connectToChild();

  if (mBounds != NULL)
  {
    mBounds->connectToParent(this);
  }

  mExperimentRefs.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "modelReference")
  {
    value = getModelReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedAdjustableParameter's attribute
 * "attributeName" is set.
 */
bool
SedAdjustableParameter::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "modelReference")
  {
    value = isSetModelReference();
  }
  else if (attributeName == "target")
  {
    value = isSetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "modelReference")
  {
    return_value = setModelReference(value);
  }
  else if (attributeName == "target")
  {
    return_value = setTarget(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "modelReference")
  {
    value = unsetModelReference();
  }
  else if (attributeName == "target")
  {
    value = unsetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this
 * SedAdjustableParameter.
 */
SedBase*
SedAdjustableParameter::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "bounds")
  {
    return createBounds();
  }
  else if (elementName == "experimentRef")
  {
    return createExperimentRef();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedAdjustableParameter.
 */
int
SedAdjustableParameter::addChildObject(const std::string& elementName,
                                       const SedBase* element)
{
  if (elementName == "bounds" && element->getTypeCode() == SEDML_BOUNDS)
  {
    return setBounds((const SedBounds*)(element));
  }
  else if (elementName == "experimentRef" && element->getTypeCode() ==
    SEDML_EXPERIMENT_REF)
  {
    return addExperimentRef((const SedExperimentRef*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedAdjustableParameter.
 */
SedBase*
SedAdjustableParameter::removeChildObject(const std::string& elementName,
                                          const std::string& id)
{
  if (elementName == "bounds")
  {
    SedBounds * obj = getBounds();
    if (unsetBounds() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "experimentRef")
  {
    for (unsigned int i = 0; i < getNumExperimentRefs(); i++)
    {
      if (getExperimentRef(i)->getId() == id)
      {
        return removeExperimentRef(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedAdjustableParameter.
 */
unsigned int
SedAdjustableParameter::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "bounds")
  {
    if (isSetBounds())
    {
      return 1;
    }
  }
  else if (elementName == "experimentRef")
  {
    return getNumExperimentRefs();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedAdjustableParameter.
 */
SedBase*
SedAdjustableParameter::getObject(const std::string& elementName,
                                  unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "bounds")
  {
    return getBounds();
  }
  else if (elementName == "experimentRef")
  {
    return getExperimentRef(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedAdjustableParameter::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  if (mBounds != NULL)
  {
    if (mBounds->getId() == id)
    {
      return mBounds;
    }

    obj = mBounds->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  obj = mExperimentRefs.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedAdjustableParameter::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "bounds")
  {
    if (isSetBounds())
    {
      getErrorLog()->logError(SedmlAdjustableParameterAllowedElements,
        getLevel(), getVersion());
    }

    delete mBounds;
    mBounds = new SedBounds(getSedNamespaces());
    obj = mBounds;
  }
  else if (name == "listOfExperimentRefs")
  {
    if (mExperimentRefs.size() != 0)
    {
      getErrorLog()->logError(SedmlAdjustableParameterAllowedElements,
        getLevel(), getVersion());
    }

    obj = &mExperimentRefs;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedAdjustableParameter::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("modelReference");

  attributes.add("target");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedAdjustableParameter::readAttributes(
                                       const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                         XMLAttributes& attributes,
                                       const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                         ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  if (log && getParentSedObject() &&
    static_cast<SedListOfAdjustableParameters*>(getParentSedObject())->size() <
      2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlParameterEstimationTaskLOAdjustableParametersAllowedCoreAttributes,
          level, version, details);
      }
    }
  }

  SedBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlAdjustableParameterAllowedAttributes, level,
          version, details);
      }
    }
  }

  // 
  // modelReference SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("modelReference", mModelReference);

  if (assigned == true)
  {
    if (mModelReference.empty() == true)
    {
      logEmptyString(mModelReference, level, version,
        "<SedAdjustableParameter>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mModelReference) == false)
    {
      std::string msg = "The modelReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mModelReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlAdjustableParameterModelReferenceMustBeModel, level,
        version, msg);
    }
  }

  // 
  // target string (use = "optional" )
  // 

  assigned = attributes.readInto("target", mTarget);

  if (assigned == true)
  {
    if (mTarget.empty() == true)
    {
      logEmptyString(mTarget, level, version, "<SedAdjustableParameter>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedAdjustableParameter::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetModelReference() == true)
  {
    stream.writeAttribute("modelReference", getPrefix(), mModelReference);
  }

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedAdjustableParameter_t using the given SEDML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t *
SedAdjustableParameter_create(unsigned int level, unsigned int version)
{
  return new SedAdjustableParameter(level, version);
}


/*
 * Creates and returns a deep copy of this SedAdjustableParameter_t object.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedAdjustableParameter_clone(const SedAdjustableParameter_t* sap)
{
  if (sap != NULL)
  {
    return static_cast<SedAdjustableParameter_t*>(sap->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAdjustableParameter_t object.
 */
LIBSEDML_EXTERN
void
SedAdjustableParameter_free(SedAdjustableParameter_t* sap)
{
  if (sap != NULL)
  {
    delete sap;
  }
}


/*
 * Returns the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
char *
SedAdjustableParameter_getModelReference(const SedAdjustableParameter_t * sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return sap->getModelReference().empty() ? NULL :
    safe_strdup(sap->getModelReference().c_str());
}


/*
 * Returns the value of the "target" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
char *
SedAdjustableParameter_getTarget(const SedAdjustableParameter_t * sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return sap->getTarget().empty() ? NULL :
    safe_strdup(sap->getTarget().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's
 * "modelReference" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetModelReference(const SedAdjustableParameter_t *
  sap)
{
  return (sap != NULL) ? static_cast<int>(sap->isSetModelReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's "target"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetTarget(const SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? static_cast<int>(sap->isSetTarget()) : 0;
}


/*
 * Sets the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setModelReference(SedAdjustableParameter_t * sap,
                                         const char * modelReference)
{
  return (sap != NULL) ? sap->setModelReference(modelReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "target" attribute of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setTarget(SedAdjustableParameter_t * sap,
                                 const char * target)
{
  return (sap != NULL) ? sap->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetModelReference(SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? sap->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetTarget(SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? sap->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "bounds" element of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
const SedBounds_t*
SedAdjustableParameter_getBounds(const SedAdjustableParameter_t * sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return (SedBounds_t*)(sap->getBounds());
}


/*
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's "bounds"
 * element is set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetBounds(const SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? static_cast<int>(sap->isSetBounds()) : 0;
}


/*
 * Sets the value of the "bounds" element of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setBounds(SedAdjustableParameter_t * sap,
                                 const SedBounds_t* bounds)
{
  return (sap != NULL) ? sap->setBounds(bounds) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedBounds_t object, adds it to this SedAdjustableParameter_t
 * object and returns the SedBounds_t object created.
 */
LIBSEDML_EXTERN
SedBounds_t*
SedAdjustableParameter_createBounds(SedAdjustableParameter_t* sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return (SedBounds_t*)(sap->createBounds());
}


/*
 * Unsets the value of the "bounds" element of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetBounds(SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? sap->unsetBounds() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedExperimentRef_t objects from this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedAdjustableParameter_getListOfExperimentRefs(SedAdjustableParameter_t* sap)
{
  return (sap != NULL) ? sap->getListOfExperimentRefs() : NULL;
}


/*
 * Get a SedExperimentRef_t from the SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedAdjustableParameter_getExperimentRef(SedAdjustableParameter_t* sap,
                                        unsigned int n)
{
  return (sap != NULL) ? sap->getExperimentRef(n) : NULL;
}


/*
 * Get a SedExperimentRef_t from the SedAdjustableParameter_t based on the
 * ExperimentId to which it refers.
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedAdjustableParameter_getExperimentRefByExperimentId(
                                                      SedAdjustableParameter_t*
                                                        sap,
                                                      const char *sid)
{
  return (sap != NULL && sid != NULL) ?
    sap->getExperimentRefByExperimentId(sid) : NULL;
}


/*
 * Adds a copy of the given SedExperimentRef_t to this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_addExperimentRef(SedAdjustableParameter_t* sap,
                                        const SedExperimentRef_t* ser)
{
  return (sap != NULL) ? sap->addExperimentRef(ser) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedExperimentRef_t objects in this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
unsigned int
SedAdjustableParameter_getNumExperimentRefs(SedAdjustableParameter_t* sap)
{
  return (sap != NULL) ? sap->getNumExperimentRefs() : SEDML_INT_MAX;
}


/*
 * Creates a new SedExperimentRef_t object, adds it to this
 * SedAdjustableParameter_t object and returns the SedExperimentRef_t object
 * created.
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedAdjustableParameter_createExperimentRef(SedAdjustableParameter_t* sap)
{
  return (sap != NULL) ? sap->createExperimentRef() : NULL;
}


/*
 * Removes the nth SedExperimentRef_t from this SedAdjustableParameter_t and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedAdjustableParameter_removeExperimentRef(SedAdjustableParameter_t* sap,
                                           unsigned int n)
{
  return (sap != NULL) ? sap->removeExperimentRef(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAdjustableParameter_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_hasRequiredAttributes(const SedAdjustableParameter_t *
  sap)
{
  return (sap != NULL) ? static_cast<int>(sap->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedAdjustableParameter_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_hasRequiredElements(const SedAdjustableParameter_t *
  sap)
{
  return (sap != NULL) ? static_cast<int>(sap->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END

