/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2014 Aleksander Morgado <aleksander@aleksander.es>
 */

#ifndef _LIBMBIM_GLIB_MBIM_COMPAT_H_
#define _LIBMBIM_GLIB_MBIM_COMPAT_H_

#if !defined (__LIBMBIM_GLIB_H_INSIDE__) && !defined (LIBMBIM_GLIB_COMPILATION)
#error "Only <libmbim-glib.h> can be included directly."
#endif

#include <glib.h>

#include "mbim-basic-connect.h"
#include "mbim-cid.h"

G_BEGIN_DECLS

/**
 * SECTION: mbim-compat
 * @title: Deprecated API
 * @short_description: Types and functions flagged as deprecated.
 *
 * This section defines types and functions that have been deprecated.
 */

#ifndef MBIM_DISABLE_DEPRECATED

/*****************************************************************************/
/* Registration flags name fixup */

/* The following type exists just so that we can get deprecation warnings */
G_DEPRECATED
typedef int MbimDeprecatedRegistrationFlag;

/**
 * MBIM_REGISTRATION_FLAG_MANUAL_PACKET_SERVICE_AUTOMATIC_ATTACH:
 *
 * Modem should auto-attach to the network after registration.
 *
 * Since: 1.0
 * Deprecated: 1.8: Use MBIM_REGISTRATION_FLAG_PACKET_SERVICE_AUTOMATIC_ATTACH instead.
 */
#define MBIM_REGISTRATION_FLAG_MANUAL_PACKET_SERVICE_AUTOMATIC_ATTACH (MbimDeprecatedRegistrationFlag) MBIM_REGISTRATION_FLAG_PACKET_SERVICE_AUTOMATIC_ATTACH

/*****************************************************************************/
/* 'Service Subscriber List' rename to 'Service Subscribe List' */

/* The following type exists just so that we can get deprecation warnings */
G_DEPRECATED
typedef int MbimDeprecatedCidBasicConnect;

/**
 * MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBER_LIST:
 *
 * Device service subscribe list.
 *
 * Since: 1.0
 * Deprecated: 1.8: Use MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBE_LIST instead.
 */
#define MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBER_LIST (MbimDeprecatedCidBasicConnect) MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBE_LIST

/**
 * mbim_message_device_service_subscriber_list_set_new:
 * @events_count: the 'EventsCount' field, given as a #guint32.
 * @events: the 'Events' field, given as an array of #MbimEventEntrys.
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Device Service Subscribe List' set command in the 'Basic Connect' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.0
 * Deprecated: 1.8: Use mbim_message_device_service_subscribe_list_set_new() instead.
 */
G_DEPRECATED_FOR (mbim_message_device_service_subscribe_list_set_new)
MbimMessage *mbim_message_device_service_subscriber_list_set_new (
    guint32 events_count,
    const MbimEventEntry *const *events,
    GError **error);

/**
 * mbim_message_device_service_subscriber_list_response_parse:
 * @message: the #MbimMessage.
 * @events_count: return location for a #guint32, or %NULL if the 'EventsCount' field is not needed.
 * @events: return location for a newly allocated array of #MbimEventEntrys, or %NULL if the 'Events' field is not needed. Free the returned value with mbim_event_entry_array_free().
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Events' response command in the 'Basic Connect' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.0
 * Deprecated: 1.8: Use mbim_message_device_service_subscribe_list_response_parse() instead.
 */
G_DEPRECATED_FOR (mbim_message_device_service_subscribe_list_response_parse)
gboolean mbim_message_device_service_subscriber_list_response_parse (
    const MbimMessage *message,
    guint32 *events_count,
    MbimEventEntry ***events,
    GError **error);

#endif /* MBIM_DISABLE_DEPRECATED */

G_END_DECLS

#endif /* _LIBMBIM_GLIB_MBIM_COMPAT_H_ */
