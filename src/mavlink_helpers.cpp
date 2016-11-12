/**
 * @brief MAVLink helpers
 * @file mavlink_helpers.cpp
 * @author Vladimir Ermakov <vooon341@gmail.com>
 *
 * This file defines replace for some helper function to prevent problem #269.
 *
 * @addtogroup mavconn
 * @{
 */
/*
 * libmavconn
 * Copyright 2015,2016 Vladimir Ermakov, All rights reserved.
 *
 * This file is part of the mavros package and subject to the license terms
 * in the top-level LICENSE file of the mavros repository.
 * https://github.com/mavlink/mavros/tree/master/LICENSE.md
 */

#include <console_bridge/console.h>
#include <mavconn/interface.h>

// AUTOMATIC GENERATED FILE!
// from src/mavlink_helpers.cpp.em

using mavconn::MAVConnInterface;

void MAVConnInterface::init_msg_entry()
{
	logDebug("mavconn: Initialize message_entries map");

	auto load = [&](const char *dialect, const mavlink::mavlink_msg_entry_t & e) {
		auto it = message_entries.find(e.msgid);
		if (it != message_entries.end()) {
			if (memcmp(&e, it->second, sizeof(e)) != 0) {
				logWarn("mavconn: init: message from %s, MSG-ID %d ignored! Table has different entry.", dialect, e.msgid);
			}
			else {
				logDebug("mavconn: init: message from %s, MSG-ID %d in table.", dialect, e.msgid);
			}
		}
		else {
			logDebug("mavconn: init: add message entry for %s, MSG-ID %d", dialect, e.msgid);
			message_entries[e.msgid] = &e;
		}
	};

	for (auto &e : mavlink::common::MESSAGE_ENTRIES)                load("common", e);
	for (auto &e : mavlink::ardupilotmega::MESSAGE_ENTRIES)         load("ardupilotmega", e);
	for (auto &e : mavlink::ASLUAV::MESSAGE_ENTRIES)                load("ASLUAV", e);
	for (auto &e : mavlink::autoquad::MESSAGE_ENTRIES)              load("autoquad", e);
	for (auto &e : mavlink::matrixpilot::MESSAGE_ENTRIES)           load("matrixpilot", e);
	for (auto &e : mavlink::minimal::MESSAGE_ENTRIES)               load("minimal", e);
	for (auto &e : mavlink::paparazzi::MESSAGE_ENTRIES)             load("paparazzi", e);
	for (auto &e : mavlink::python_array_test::MESSAGE_ENTRIES)     load("python_array_test", e);
	for (auto &e : mavlink::slugs::MESSAGE_ENTRIES)                 load("slugs", e);
	for (auto &e : mavlink::test::MESSAGE_ENTRIES)                  load("test", e);
	for (auto &e : mavlink::ualberta::MESSAGE_ENTRIES)              load("ualberta", e);
	
}

std::vector<std::string> MAVConnInterface::get_known_dialects()
{
	return {
		"common",
		"ardupilotmega",
		"ASLUAV",
		"autoquad",
		"matrixpilot",
		"minimal",
		"paparazzi",
		"python_array_test",
		"slugs",
		"test",
		"ualberta",
		
	};
}

/**
 * Internal function to give access to message information such as additional crc byte.
 */
const mavlink::mavlink_msg_entry_t* mavlink::mavlink_get_msg_entry(uint32_t msgid)
{
	auto it = MAVConnInterface::message_entries.find(msgid);
	if (it != MAVConnInterface::message_entries.end())
		return it->second;
	else
		return nullptr;
}
