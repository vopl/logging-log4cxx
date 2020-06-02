/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _LOG4CXX_FILTER_MAPFILTER_H
#define _LOG4CXX_FILTER_MAPFILTER_H

#include <log4cxx/spi/filter.h>

#if defined(_MSC_VER)
	#pragma warning ( push )
	#pragma warning ( disable: 4251 )
#endif

namespace log4cxx
{
namespace filter
{
/**
 * A Filter that operates on a Map.
 */

 using keyvallist = std::map<LogString, LogString>;

class LOG4CXX_EXPORT MapFilter: public log4cxx::spi::Filter
{
	private:
		bool acceptOnMatch{true};
		bool mustMatchAll{false};	// true = AND; false = OR
		keyvallist mapKeyValList;

	public:
		DECLARE_LOG4CXX_OBJECT(MapFilter)
		BEGIN_LOG4CXX_CAST_MAP()
		LOG4CXX_CAST_ENTRY(MapFilter)
		LOG4CXX_CAST_ENTRY_CHAIN(log4cxx::spi::Filter)
		END_LOG4CXX_CAST_MAP()

		MapFilter(){}

		/**
		Set options
		*/
		virtual void setOption(const LogString& option,
			const LogString& value);

		inline void setKeyValue(const LogString& strKey, const LogString& strValue)
		{
			this->mapKeyValList[strKey] = strValue;
		}

		inline const LogString& getValue(const LogString& strKey) const
		{
			static const LogString empty{};
			auto it = mapKeyValList.find(strKey);
			return (it != mapKeyValList.end() ? it->second : empty);
		}

		inline void setAcceptOnMatch(bool acceptOnMatch1)
		{
			this->acceptOnMatch = acceptOnMatch1;
		}

		inline bool getAcceptOnMatch() const
		{
			return acceptOnMatch;
		}

		inline bool getMustMatchAll() const
		{
			return mustMatchAll;
		}

		inline void setMustMatchAll(bool mustMatchAll1)
		{
			this->mustMatchAll = mustMatchAll1;
		}

		/**
		Returns {@link log4cxx::spi::Filter#NEUTRAL NEUTRAL}
		is there is no string match.
		*/
		FilterDecision decide(const spi::LoggingEventPtr& event) const;
}; // class MapFilter
LOG4CXX_PTR_DEF(MapFilter);
}  // namespace filter
} // namespace log4cxx

#if defined(_MSC_VER)
	#pragma warning (pop)
#endif

#endif // _LOG4CXX_FILTER_MAPFILTER_H
