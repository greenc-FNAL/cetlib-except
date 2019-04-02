.. cetlib documentation master file, created by
   sphinx-quickstart on Sun Jul  8 22:29:32 2018.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

*cetlib_except* library
================

.. toctree::
   :maxdepth: 2

* `Release notes <releaseNotes.html>`_

* `Depends on <depends.html>`_

The cetlib_except C++ library is a subset of the *project:cetlib* (FIX THIS LINK?) library, designed to minimize coupling to external products while still providing exception facilities.  As such, the only dependency is on the C++ standard library provided by the compiler.  The facilities provided are:


.. note:: A subset of the *cetlib* library is the *cetlib_except*
   library, which includes exception utilities and a symbol demangler.


* :rsource:`cetlib_except/coded_exception.h`: A family of enumeration-based exception types.
* :rsource:`cetlib_except/demangle.h`: Call the cross-vendor API to demangle symbols.
* :rsource:`cetlib_except/exception.h`: An exception type with category capability.
* :rsource:`cetlib_except/exception_collector.h`: Ensure that each function/functor in a sequence of calls is invoked even if a previous function throws.

