/**
 * @file    SedWriter.h
 * @brief   Writes an Sed Document to file or in-memory string
 * @author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSed.  Please visit http://sbml.org for more
 * information about Sed, and the latest version of libSed.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedWriter
 * @ingroup Core
 * @brief Methods for writing Sed to files and text strings.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * The SedWriter class is the converse of SedReader, and provides the
 * main interface for serializing Sed models into XML and writing the
 * result to files and text strings.  The methods for writing Sed all take
 * an SedDocument object and a destination.  They return a boolean or
 * integer value to indicate success or failure.
 *
 * @section compression Support for writing compressed files
 *
 * LibSed provides support for writing (as well as reading) compressed
 * Sed files.  The process is transparent to the calling
 * application&mdash;the application does not need to do anything
 * deliberate to invoke the functionality.  If a given Sed filename ends
 * with an extension for the @em gzip, @em zip or @em bzip2 compression
 * formats (respectively, <code>&quot;.gz&quot;</code>,
 * <code>&quot;.zip&quot;</code>, or <code>&quot;.bz2&quot;</code>),
 * then the methods
 * SedWriter::writeSed(@if java SedDocument d, String filename@endif)
 * and SedReader::readSed(@if java String filename@endif)
 * will automatically compress and decompress the file while writing and
 * reading it.  If the filename has no such extension, it
 * will be written and read uncompressed as normal.
 *
 * The compression feature requires that the @em zlib (for @em gzip and @em
 * zip formats) and/or @em bzip2 (for @em bzip2 format) be available on the
 * system running libSed, and that libSed was configured with their
 * support compiled-in.  Please see the libSed @if clike <a href="libsbml-installation.html">installation instructions</a>@endif@if python <a href="libsbml-installation.html">installation instructions</a>@endif@if java  <a href="../../../libsbml-installation.html">installation instructions</a>@endif@~ for 
 * more information about this.  The methods
 * SedWriter::hasZlib() and
 * SedWriter::hasBzip2()
 * can be used by an application to query at run-time whether support
 * for the compression libraries is available in the present copy of
 * libSed.
 *
 * Support for compression is not mandated by the Sed standard, but
 * applications may find it helpful, particularly when large Sed models
 * are being communicated across data links of limited bandwidth.
 */

#ifndef SedWriter_h
#define SedWriter_h


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <iosfwd>
#include <string>

LIBSEDML_CPP_NAMESPACE_BEGIN

class SedDocument;


class LIBSEDML_EXTERN SedWriter
{
public:

  /**
   * Creates a new SedWriter.
   *
   * The libSed SedWriter objects offer methods for writing Sed in
   * XML form to files and text strings.
   */
  SedWriter  ();


  /**
   * Destroys this SedWriter.
   */
  ~SedWriter ();


  /**
   * Sets the name of this program, i.e., the program that is about to
   * write out the SedDocument.
   *
   * If the program name and version are set (see
   * SedWriter::setProgramVersion(@if java String version@endif)), the
   * following XML comment, intended for human consumption, will be written
   * at the beginning of the XML document:
   * @verbatim
 <!-- Created by <program name> version <program version>
 on yyyy-MM-dd HH:mm with libSed version <libsbml version>. -->
 @endverbatim
   *
   * If the program name and version are not set at some point before
   * calling the writeSed() methods, no such comment is written out.
   *
   * @param name the name of this program (where "this program" refers to
   * program in which libSed is embedded, not libSed itself!)
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values
   * returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * 
   * @see setProgramVersion(const std::string& version)
   */
  int setProgramName (const std::string& name);


  /**
   * Sets the version of this program, i.e., the program that is about to
   * write out the SedDocument.
   *
   * If the program version and name are set (see
   * SedWriter::setProgramName(@if java String name@endif)), the
   * following XML comment, intended for human consumption, will be written
   * at the beginning of the document:
   * @verbatim
 <!-- Created by <program name> version <program version>
 on yyyy-MM-dd HH:mm with libSed version <libsbml version>. -->
 @endverbatim
   *
   * If the program version and name are not set at some point before
   * calling the writeSed() methods, no such comment is written out.
   *
   * @param version the version of this program (where "this program"
   * refers to program in which libSed is embedded, not libSed itself!)
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values
   * returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   *
   * @see setProgramName(const std::string& name)
   */
  int setProgramVersion (const std::string& version);


  /**
   * Writes the given Sed document to filename.
   *
   * @htmlinclude assuming-compressed-file.html
   *
   * @param d the Sed document to be written
   *
   * @param filename the name or full pathname of the file where the Sed
   * is to be written. 
   *
   * @return @c true on success and @c false if the filename could not be
   * opened for writing.
   *
   * @note @htmlinclude note-writing-zipped-files.html
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  bool writeSed (const SedDocument* d, const std::string& filename);


  /**
   * Writes the given Sed document to the output stream.
   *
   * @param d the Sed document to be written
   *
   * @param stream the stream object where the Sed is to be written.
   *
   * @return @c true on success and @c false if one of the underlying
   * parser components fail (rare).
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  bool writeSed (const SedDocument* d, std::ostream& stream);


  /** @cond doxygen-libsbml-internal */

  /**
   * Writes the given Sed document to an in-memory string and returns a
   * pointer to it.
   *
   * The string is owned by the caller and should be freed (with @c free())
   * when no longer needed.
   *
   * @param d the Sed document to be written
   *
   * @return the string on success and @c 0 if one of the underlying parser
   * components fail.
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  char* writeToString (const SedDocument* d);

  /** @endcond */

  /**
   * Writes the given Sed document to filename.
   *
   * @htmlinclude assuming-compressed-file.html
   *
   * @param d the Sed document to be written
   *
   * @param filename the name or full pathname of the file where the Sed
   * is to be written. 
   *
   * @return @c true on success and @c false if the filename could not be
   * opened for writing.
   *
   * @note @htmlinclude note-writing-zipped-files.html
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  bool writeSedToFile (const SedDocument* d, const std::string& filename);


  /**
   * Writes the given Sed document to an in-memory string and returns a
   * pointer to it.
   *
   * The string is owned by the caller and should be freed (with @c free())
   * when no longer needed.
   *
   * @param d the Sed document to be written
   *
   * @return the string on success and @c 0 if one of the underlying parser
   * components fail.
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  char* writeSedToString (const SedDocument* d);


  /**
   * Predicate returning @c true if this copy of libSed has been linked
   * with the <em>zlib</em> library.
   *
   * LibSed supports reading and writing files compressed with either
   * bzip2 or zip/gzip compression.  The facility depends on libSed having
   * been compiled with the necessary support libraries.  This method
   * allows a calling program to inquire whether that is the case for the
   * copy of libSed it is using.
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSed will contain two variants.  One
   * will be a static method on the class (i.e., SedWriter), and the other
   * will be a standalone top-level function with the name
   * SedWriter_hasZlib(). They are functionally identical. @endif@~
   *
   * @return @c true if libSed is linked with zlib, @c false otherwise.
   *
   * @see @if clike hasBzip2() @else SedWriter::hasBzip2() @endif@~
   */
  static bool hasZlib();


  /**
   * Predicate returning @c true if this copy of libSed has been linked
   * with the <em>bzip2</em> library.
   *
   * LibSed supports reading and writing files compressed with either
   * bzip2 or zip/gzip compression.  The facility depends on libSed having
   * been compiled with the necessary support libraries.  This method
   * allows a calling program to inquire whether that is the case for the
   * copy of libSed it is using.
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSed will contain two variants.  One
   * will be a static method on the class (i.e., SedWriter), and the other
   * will be a standalone top-level function with the name
   * SedWriter_hasZlib(). They are functionally identical. @endif@~
   *
   * @return @c true if libSed is linked with bzip2, @c false otherwise.
   *
   * @see @if clike hasZlib() @else SedWriter::hasZlib() @endif@~
   */
  static bool hasBzip2();


 protected:
  /** @cond doxygen-libsbml-internal */

  std::string mProgramName;
  std::string mProgramVersion;

  /** @endcond */
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */


LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


#ifndef SWIG


/**
 * Creates a new SedWriter and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedWriter_t *
SedWriter_create (void);

/**
 * Frees the given SedWriter.
 */
LIBSEDML_EXTERN
void
SedWriter_free (SedWriter_t *sw);

/**
 * Sets the name of this program. i.\ e.\ the one about to write out the
 * SedDocument.  If the program name and version are set
 * (setProgramVersion()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libSed version <libsbml version>. -->
 */
LIBSEDML_EXTERN
int
SedWriter_setProgramName (SedWriter_t *sw, const char *name);

/**
 * Sets the version of this program. i.\ e.\ the one about to write out the
 * SedDocument.  If the program version and name are set
 * (setProgramName()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libSed version <libsbml version>. -->
 */
LIBSEDML_EXTERN
int
SedWriter_setProgramVersion (SedWriter_t *sw, const char *version);

/**
 * Writes the given Sed document to filename.
 *
 * @htmlinclude assuming-compressed-file.html
 *
 * @return non-zero on success and zero if the filename could not be opened
 * for writing.
 *
 * @note To write a gzip/zip file, libSed needs to be configured and
 * linked with the <a target="_blank" href="http://www.zlib.net/">zlib</a> library at
 * compile time.  It also needs to be linked with the <a target="_blank"
 * href="">bzip2</a> library to write files in @em bzip2 format.  (Both
 * of these are the default configurations for libSed.)  Errors about
 * unreadable files will be logged and this method will return @c false
 * if a compressed filename is given and libSed was @em not linked with
 * the corresponding required library.
 *
 * @note SedReader::hasZlib() and SedReader::hasBzip2() can be used to
 * check whether libSed has been linked with each library.
 */
LIBSEDML_EXTERN
int
SedWriter_writeSed ( SedWriter_t         *sw,
                       const SedDocument_t *d,
                       const char           *filename );

LIBSEDML_EXTERN
int
SedWriter_writeSedToFile ( SedWriter_t         *sw,
                       const SedDocument_t *d,
                       const char           *filename );


/**
 * Writes the given Sed document to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @return the string on success and @c NULL if one of the underlying parser
 * components fail (rare).
 */
LIBSEDML_EXTERN
char *
SedWriter_writeSedToString (SedWriter_t *sw, const SedDocument_t *d);


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * libSed is linked with zlib at compile time.
 *
 * @return @c non-zero if zlib is linked, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedWriter_hasZlib ();


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * libSed is linked with bzip2 at compile time.
 *
 * @return @c non-zero if bzip2 is linked, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedWriter_hasBzip2 ();

#endif  /* !SWIG */


/**
 * Writes the given Sed document @p d to the file named by @p filename.
 *
 * This function is identical to @if clike SedWriter::writeSedToFile (const SedDocument_t *d, const char *filename)@endif@if java <a href="#writeSedToFile(org.sbml.libsbml.SedDocument, java.lang.String)"><code>writeSedToFile(SedDocument d, String filename)</code></a>@endif.
 * 
 * @htmlinclude assuming-compressed-file.html
 *
 * @param d the SedDocument object to be written out in XML format
 * 
 * @param filename a string giving the path to a file where the XML
 * content is to be written.
 *
 * @return @c 1 on success and @c 0 (zero) if @p filename could not be
 * written.  Some possible reasons for failure include (a) being unable to
 * open the file, and (b) using a filename that indicates a compressed Sed
 * file (i.e., a filename ending in <code>&quot;.zip&quot;</code> or
 * similar) when the compression functionality has not been enabled in
 * the underlying copy of libSed.
 *
 * @if clike @warning Note that the string is owned by the caller and
 * should be freed (with the normal string <code>free()</code> C++
 * function) after it is no longer needed.@endif@~
 *
 * @see SedWriter::hasZlib()
 * @see SedWriter::hasBzip2()
 */
LIBSEDML_EXTERN
int
writeSed (const SedDocument_t *d, const char *filename);


/**
 * Writes the given Sed document @p d to an in-memory string and
 * returns the string.
 *
 * This is a convenience function that uses the
 * SedWriter::writeSedToString(const SedDocument* d) method internally,
 * yet does not require the caller to create an SedWriter object first.
 *
 * @param d an SedDocument object to be written out in XML format
 *
 * @return the string on success and @c NULL if one of the underlying parser
 * components fail.
 *
 * @if clike @warning Note that the string is owned by the caller and
 * should be freed (with the normal string <code>free()</code> C++
 * function) after it is no longer needed.@endif@~
 */
LIBSEDML_EXTERN
char *
writeSedToString (const SedDocument_t *d);


/**
 * Writes the given Sed document @p d to the file @p filename.
 *
 * This is a convenience function that uses the
 * SedWriter::writeSedToFile(const SedDocument* d, const std::string&
 * filename) method internally, yet does not require the caller to create
 * an SedWriter object first.
 *
 * @htmlinclude assuming-compressed-file.html
 * 
 * @param d an SedDocument object to be written out in XML format
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be written.
 *
 * @return @c 1 on success and @c 0 (zero) if @p filename could not be
 * written.  Some possible reasons for failure include (a) being unable to
 * open the file, and (b) using a filename that indicates a compressed Sed
 * file (i.e., a filename ending in <code>&quot;.zip&quot;</code> or
 * similar) when the compression functionality has not been enabled in
 * the underlying copy of libSed.
 *
 * @if clike @warning Note that the string is owned by the caller and
 * should be freed (with the normal string <code>free()</code> C++
 * function) after it is no longer needed.@endif@~
 *
 * @see SedWriter::hasZlib()
 * @see SedWriter::hasBzip2()
 */
LIBSEDML_EXTERN
int
writeSedToFile (const SedDocument_t *d, const char *filename);


END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* SedWriter_h */