/*
 * Copyright 2003-2005 The Apache Software Foundation.
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

#include <log4cxx/portability.h>

#ifdef HAVE_XML

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <log4cxx/logmanager.h>
#include <log4cxx/logger.h>
#include "../insertwide.h"

using namespace log4cxx;

class TestCase4 : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestCase4);
		CPPUNIT_TEST(combinedTest);
	CPPUNIT_TEST_SUITE_END();
	
public:
	void setUp()
	{
	}

	void tearDown()
	{
		LogManager::shutdown();
	}
	
	void combinedTest()
	{
		LoggerPtr root = Logger::getRootLogger();
		bool rootIsConfigured = !root->getAllAppenders().empty();
		CPPUNIT_ASSERT(rootIsConfigured);
		
		AppenderList list = root->getAllAppenders();
		CPPUNIT_ASSERT_EQUAL((size_t) 1, list.size());
		AppenderPtr appender = list.front();
		CPPUNIT_ASSERT_EQUAL((LogString) LOG4CXX_STR("D1"), appender->getName());
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION(TestCase4);

#endif //HAVE_XML
