/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 * libmbim-glib -- GLib/GIO based library to control MBIM devices
 *
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
 * Copyright (C) 2013 - 2018 Aleksander Morgado <aleksander@aleksander.es>
 */

#ifndef _LIBMBIM_GLIB_MBIM_CID_H_
#define _LIBMBIM_GLIB_MBIM_CID_H_

#if !defined (__LIBMBIM_GLIB_H_INSIDE__) && !defined (LIBMBIM_GLIB_COMPILATION)
#error "Only <libmbim-glib.h> can be included directly."
#endif

#include <glib.h>

#include "mbim-uuid.h"

G_BEGIN_DECLS

/**
 * SECTION: mbim-cid
 * @title: Command IDs
 * @short_description: Generic command handling routines.
 *
 * This section defines the interface of the known command IDs.
 */

/**
 * MbimCidBasicConnect:
 * @MBIM_CID_BASIC_CONNECT_UNKNOWN: Unknown command.
 * @MBIM_CID_BASIC_CONNECT_DEVICE_CAPS: Device capabilities.
 * @MBIM_CID_BASIC_CONNECT_SUBSCRIBER_READY_STATUS: Subscriber ready status.
 * @MBIM_CID_BASIC_CONNECT_RADIO_STATE: Radio state.
 * @MBIM_CID_BASIC_CONNECT_PIN: PIN.
 * @MBIM_CID_BASIC_CONNECT_PIN_LIST: PIN list.
 * @MBIM_CID_BASIC_CONNECT_HOME_PROVIDER: Home provider.
 * @MBIM_CID_BASIC_CONNECT_PREFERRED_PROVIDERS: Preferred providers.
 * @MBIM_CID_BASIC_CONNECT_VISIBLE_PROVIDERS: Visible providers.
 * @MBIM_CID_BASIC_CONNECT_REGISTER_STATE: Register state.
 * @MBIM_CID_BASIC_CONNECT_PACKET_SERVICE: Packet service.
 * @MBIM_CID_BASIC_CONNECT_SIGNAL_STATE: Signal state.
 * @MBIM_CID_BASIC_CONNECT_CONNECT: Connect.
 * @MBIM_CID_BASIC_CONNECT_PROVISIONED_CONTEXTS: Provisioned contexts.
 * @MBIM_CID_BASIC_CONNECT_SERVICE_ACTIVATION: Service activation.
 * @MBIM_CID_BASIC_CONNECT_IP_CONFIGURATION: IP configuration.
 * @MBIM_CID_BASIC_CONNECT_DEVICE_SERVICES: Device services.
 * @MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBE_LIST: Device service subscribe list. Since 1.8.
 * @MBIM_CID_BASIC_CONNECT_PACKET_STATISTICS: Packet statistics.
 * @MBIM_CID_BASIC_CONNECT_NETWORK_IDLE_HINT: Network idle hint.
 * @MBIM_CID_BASIC_CONNECT_EMERGENCY_MODE: Emergency mode.
 * @MBIM_CID_BASIC_CONNECT_IP_PACKET_FILTERS: IP packet filters.
 * @MBIM_CID_BASIC_CONNECT_MULTICARRIER_PROVIDERS: Multicarrier providers.
 *
 * MBIM commands in the %MBIM_SERVICE_BASIC_CONNECT service.
 *
 * Since: 1.0
 */
typedef enum { /*< since=1.0 >*/
    MBIM_CID_BASIC_CONNECT_UNKNOWN                        = 0,
    MBIM_CID_BASIC_CONNECT_DEVICE_CAPS                    = 1,
    MBIM_CID_BASIC_CONNECT_SUBSCRIBER_READY_STATUS        = 2,
    MBIM_CID_BASIC_CONNECT_RADIO_STATE                    = 3,
    MBIM_CID_BASIC_CONNECT_PIN                            = 4,
    MBIM_CID_BASIC_CONNECT_PIN_LIST                       = 5,
    MBIM_CID_BASIC_CONNECT_HOME_PROVIDER                  = 6,
    MBIM_CID_BASIC_CONNECT_PREFERRED_PROVIDERS            = 7,
    MBIM_CID_BASIC_CONNECT_VISIBLE_PROVIDERS              = 8,
    MBIM_CID_BASIC_CONNECT_REGISTER_STATE                 = 9,
    MBIM_CID_BASIC_CONNECT_PACKET_SERVICE                 = 10,
    MBIM_CID_BASIC_CONNECT_SIGNAL_STATE                   = 11,
    MBIM_CID_BASIC_CONNECT_CONNECT                        = 12,
    MBIM_CID_BASIC_CONNECT_PROVISIONED_CONTEXTS           = 13,
    MBIM_CID_BASIC_CONNECT_SERVICE_ACTIVATION             = 14,
    MBIM_CID_BASIC_CONNECT_IP_CONFIGURATION               = 15,
    MBIM_CID_BASIC_CONNECT_DEVICE_SERVICES                = 16,
    /* 17, 18 reserved */
    MBIM_CID_BASIC_CONNECT_DEVICE_SERVICE_SUBSCRIBE_LIST  = 19,
    MBIM_CID_BASIC_CONNECT_PACKET_STATISTICS              = 20,
    MBIM_CID_BASIC_CONNECT_NETWORK_IDLE_HINT              = 21,
    MBIM_CID_BASIC_CONNECT_EMERGENCY_MODE                 = 22,
    MBIM_CID_BASIC_CONNECT_IP_PACKET_FILTERS              = 23,
    MBIM_CID_BASIC_CONNECT_MULTICARRIER_PROVIDERS         = 24,
} MbimCidBasicConnect;

/**
 * MbimCidSms:
 * @MBIM_CID_SMS_UNKNOWN: Unknown command.
 * @MBIM_CID_SMS_CONFIGURATION: SMS configuration.
 * @MBIM_CID_SMS_READ: Read.
 * @MBIM_CID_SMS_SEND: Send.
 * @MBIM_CID_SMS_DELETE: Delete.
 * @MBIM_CID_SMS_MESSAGE_STORE_STATUS: Store message status.
 *
 * MBIM commands in the %MBIM_SERVICE_SMS service.
 *
 * Since: 1.0
 */
typedef enum { /*< since=1.0 >*/
    MBIM_CID_SMS_UNKNOWN              = 0,
    MBIM_CID_SMS_CONFIGURATION        = 1,
    MBIM_CID_SMS_READ                 = 2,
    MBIM_CID_SMS_SEND                 = 3,
    MBIM_CID_SMS_DELETE               = 4,
    MBIM_CID_SMS_MESSAGE_STORE_STATUS = 5,
} MbimCidSms;

/**
 * MbimCidUssd:
 * @MBIM_CID_USSD_UNKNOWN: Unknown command. Since 1.4.
 * @MBIM_CID_USSD: USSD operation.
 *
 * MBIM commands in the %MBIM_SERVICE_USSD service.
 *
 * Since: 1.0
 */
typedef enum { /*< since=1.0 >*/
    MBIM_CID_USSD_UNKNOWN = 0,
    MBIM_CID_USSD         = 1,
} MbimCidUssd;

/**
 * MbimCidPhonebook:
 * @MBIM_CID_PHONEBOOK_UNKNOWN: Unknown command.
 * @MBIM_CID_PHONEBOOK_CONFIGURATION: Configuration.
 * @MBIM_CID_PHONEBOOK_READ: Read.
 * @MBIM_CID_PHONEBOOK_DELETE: Delete.
 * @MBIM_CID_PHONEBOOK_WRITE: Write.
 *
 * MBIM commands in the %MBIM_SERVICE_PHONEBOOK service.
 *
 * Since: 1.0
 */
typedef enum { /*< since=1.0 >*/
    MBIM_CID_PHONEBOOK_UNKNOWN       = 0,
    MBIM_CID_PHONEBOOK_CONFIGURATION = 1,
    MBIM_CID_PHONEBOOK_READ          = 2,
    MBIM_CID_PHONEBOOK_DELETE        = 3,
    MBIM_CID_PHONEBOOK_WRITE         = 4,
} MbimCidPhonebook;

/**
 * MbimCidStk:
 * @MBIM_CID_STK_UNKNOWN: Unknown command.
 * @MBIM_CID_STK_PAC: PAC.
 * @MBIM_CID_STK_TERMINAL_RESPONSE: Terminal response.
 * @MBIM_CID_STK_ENVELOPE: Envelope.
 *
 * MBIM commands in the %MBIM_SERVICE_STK service.
 *
 * Since: 1.0
 */
typedef enum { /*< since=1.0 >*/
    MBIM_CID_STK_UNKNOWN           = 0,
    MBIM_CID_STK_PAC               = 1,
    MBIM_CID_STK_TERMINAL_RESPONSE = 2,
    MBIM_CID_STK_ENVELOPE          = 3,
} MbimCidStk;

/**
 * MbimCidAuth:
 * @MBIM_CID_AUTH_UNKNOWN: Unknow command
 * @MBIM_CID_AUTH_AKA: AKA.
 * @MBIM_CID_AUTH_AKAP: AKAP.
 * @MBIM_CID_AUTH_SIM: SIM.
 *
 * MBIM commands in the %MBIM_SERVICE_AUTH service.
 *
 * Since: 1.0
 */
typedef enum { /*< since=1.0 >*/
    MBIM_CID_AUTH_UNKNOWN = 0,
    MBIM_CID_AUTH_AKA     = 1,
    MBIM_CID_AUTH_AKAP    = 2,
    MBIM_CID_AUTH_SIM     = 3,
} MbimCidAuth;

/**
 * MbimCidDss:
 * @MBIM_CID_DSS_UNKNOWN: Unknown command.
 * @MBIM_CID_DSS_CONNECT: Connect.
 *
 * MBIM commands in the %MBIM_SERVICE_DSS service.
 *
 * Since: 1.0
 */
typedef enum { /*< since=1.0 >*/
    MBIM_CID_DSS_UNKNOWN = 0,
    MBIM_CID_DSS_CONNECT = 1
} MbimCidDss;

/**
 * MbimCidMsFirmwareId:
 * @MBIM_CID_MS_FIRMWARE_ID_UNKNOWN: Unknown command.
 * @MBIM_CID_MS_FIRMWARE_ID_GET: Get Firmware ID.
 *
 * MBIM commands in the %MBIM_SERVICE_MS_FIRMWARE_ID service.
 *
 * Since: 1.8
 */
typedef enum { /*< since=1.0 >*/
    MBIM_CID_MS_FIRMWARE_ID_UNKNOWN = 0,
    MBIM_CID_MS_FIRMWARE_ID_GET     = 1
} MbimCidMsFirmwareId;

/**
 * MbimCidMsHostShutdown:
 * @MBIM_CID_MS_HOST_SHUTDOWN_UNKNOWN: Unknown command.
 * @MBIM_CID_MS_HOST_SHUTDOWN_NOTIFY: Notify that the host is shutting down.
 *
 * MBIM commands in the %MBIM_SERVICE_MS_HOST_SHUTDOWN service.
 *
 * Since: 1.8
 */
typedef enum { /*< since=1.8 >*/
    MBIM_CID_MS_HOST_SHUTDOWN_UNKNOWN = 0,
    MBIM_CID_MS_HOST_SHUTDOWN_NOTIFY  = 1
} MbimCidMsHostShutdown;

/**
 * MbimCidProxyControl:
 * @MBIM_CID_PROXY_CONTROL_UNKNOWN: Unknown command.
 * @MBIM_CID_PROXY_CONTROL_CONFIGURATION: Configuration.
 *
 * MBIM commands in the %MBIM_SERVICE_PROXY_CONTROL service.
 *
 * Since: 1.10
 */
typedef enum { /*< since=1.10 >*/
    MBIM_CID_PROXY_CONTROL_UNKNOWN       = 0,
    MBIM_CID_PROXY_CONTROL_CONFIGURATION = 1
} MbimCidProxyControl;

/**
 * MbimCidQmi:
 * @MBIM_CID_QMI_UNKNOWN: Unknown command.
 * @MBIM_CID_QMI_MSG: Send QMI request and receive QMI response.
 *
 * MBIM commands in the %MBIM_SERVICE_QMI service.
 *
 * Since: 1.14
 */
typedef enum { /*< since=1.14 >*/
    MBIM_CID_QMI_UNKNOWN = 0,
    MBIM_CID_QMI_MSG     = 1
} MbimCidQmi;

/**
 * MbimCidAtds:
 * @MBIM_CID_ATDS_UNKNOWN: Unknown command.
 * @MBIM_CID_ATDS_SIGNAL: Radio signal information.
 * @MBIM_CID_ATDS_LOCATION: Cell location information.
 * @MBIM_CID_ATDS_OPERATORS: Operator selection.
 * @MBIM_CID_ATDS_RAT: Radio Access Technology selection.
 * @MBIM_CID_ATDS_REGISTER_STATE: Registration state.
 *
 * MBIM commands in the %MBIM_SERVICE_ATDS service.
 *
 * Since: 1.16
 */
typedef enum { /*< since=1.16 >*/
    MBIM_CID_ATDS_UNKNOWN        = 0,
    MBIM_CID_ATDS_SIGNAL         = 1,
    MBIM_CID_ATDS_LOCATION       = 2,
    MBIM_CID_ATDS_OPERATORS      = 3,
    MBIM_CID_ATDS_RAT            = 4,
    MBIM_CID_ATDS_REGISTER_STATE = 9,
} MbimCidAtds;

/**
 * MbimCidIntelFirmwareUpdate:
 * @MBIM_CID_INTEL_FIRMWARE_UPDATE_UNKNOWN: Unknown command.
 * @MBIM_CID_INTEL_FIRMWARE_UPDATE_MODEM_REBOOT: Reboot modem for firmware update.
 *
 * MBIM commands in the %MBIM_SERVICE_INTEL_FIRMWARE_UPDATE service.
 *
 * Since: 1.16
 */
typedef enum { /*< since=1.16 >*/
    MBIM_CID_INTEL_FIRMWARE_UPDATE_UNKNOWN      = 0,
    MBIM_CID_INTEL_FIRMWARE_UPDATE_MODEM_REBOOT = 1,
} MbimCidIntelFirmwareUpdate;

/**
 * MbimCidMsBasicConnectExtensions:
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_UNKNOWN: Unknown command.
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_PROVISIONED_CONTEXTS: Provisioned contexts (v2).
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_NETWORK_BLACKLIST: Network blacklist.
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_LTE_ATTACH_CONFIGURATION: LTE attach configuration.
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_LTE_ATTACH_STATUS: LTE attach status.
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_SYS_CAPS: System capabilities.
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_DEVICE_CAPS: Device capabilities (v2).
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_DEVICE_SLOT_MAPPINGS: Device slot mappings.
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_SLOT_INFO_STATUS: Slot info status.
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_PCO: Protocol configuration operations (PCO).
 * @MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_DEVICE_RESET: Device reset.
 *
 * MBIM commands in the %MBIM_SERVICE_MS_BASIC_CONNECT_EXTENSIONS service.
 *
 * Since: 1.18
 */
typedef enum { /*< since=1.18 >*/
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_UNKNOWN                  = 0,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_PROVISIONED_CONTEXTS     = 1,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_NETWORK_BLACKLIST        = 2,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_LTE_ATTACH_CONFIGURATION = 3,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_LTE_ATTACH_STATUS        = 4,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_SYS_CAPS                 = 5,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_DEVICE_CAPS              = 6,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_DEVICE_SLOT_MAPPINGS     = 7,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_SLOT_INFO_STATUS         = 8,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_PCO                      = 9,
    MBIM_CID_MS_BASIC_CONNECT_EXTENSIONS_DEVICE_RESET             = 10,
} MbimCidMsBasicConnectExtensions;

/* Command helpers */

/**
 * mbim_cid_can_set:
 * @service: a #MbimService.
 * @cid: a command ID.
 *
 * Checks whether the given command allows setting.
 *
 * Returns: %TRUE if the command allows setting, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean mbim_cid_can_set (MbimService service,
                           guint       cid);

/**
 * mbim_cid_can_query:
 * @service: a #MbimService.
 * @cid: a command ID.
 *
 * Checks whether the given command allows querying.
 *
 * Returns: %TRUE if the command allows querying, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean mbim_cid_can_query (MbimService service,
                             guint       cid);

/**
 * mbim_cid_can_notify:
 * @service: a #MbimService.
 * @cid: a command ID.
 *
 * Checks whether the given command allows notifying.
 *
 * Returns: %TRUE if the command allows notifying, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean mbim_cid_can_notify (MbimService service,
                              guint       cid);


/**
 * mbim_cid_get_printable:
 * @service: a #MbimService.
 * @cid: a command ID.
 *
 * Gets a printable string for the command specified by the @service and the
 * @cid.
 *
 * Returns: a constant string.
 *
 * Since: 1.0
 */
const gchar *mbim_cid_get_printable (MbimService service,
                                     guint       cid);

G_END_DECLS

#endif /* _LIBMBIM_GLIB_MBIM_CID_H_ */
