/*
 * Copyright 2004 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cppunit/TestFixture.h>
#include <log4cxx/writerappender.h>
#include "appenderskeletontestcase.h"


/**
   An abstract set of tests for inclusion in concrete
   appender test case
 */
class WriterAppenderTestCase : public AppenderSkeletonTestCase
{

public:
        log4cxx::AppenderSkeleton* createAppenderSkeleton() const;

        virtual log4cxx::WriterAppender* createWriterAppender() const = 0;

};