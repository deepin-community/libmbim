/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * libmbim-glib -- GLib/GIO based library to control MBIM devices
 *
 * Copyright (C) 2021 Aleksander Morgado <aleksander@aleksander.es>
 *
 * Based on the QmiNetPortManagerRmnet from libqmi:
 *   Copyright (C) 2020-2021 Eric Caruso <ejcaruso@chromium.org>
 *   Copyright (C) 2020-2021 Andrew Lassalle <andrewlassalle@chromium.org>
 */

#ifndef _LIBMBIM_GLIB_MBIM_NET_PORT_MANAGER_H_
#define _LIBMBIM_GLIB_MBIM_NET_PORT_MANAGER_H_

#include <gio/gio.h>
#include <glib-object.h>

#define MBIM_TYPE_NET_PORT_MANAGER            (mbim_net_port_manager_get_type ())
#define MBIM_NET_PORT_MANAGER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MBIM_TYPE_NET_PORT_MANAGER, MbimNetPortManager))
#define MBIM_NET_PORT_MANAGER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  MBIM_TYPE_NET_PORT_MANAGER, MbimNetPortManagerClass))
#define MBIM_IS_NET_PORT_MANAGER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MBIM_TYPE_NET_PORT_MANAGER))
#define MBIM_IS_NET_PORT_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  MBIM_TYPE_NET_PORT_MANAGER))
#define MBIM_NET_PORT_MANAGER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  MBIM_TYPE_NET_PORT_MANAGER, MbimNetPortManagerClass))

typedef struct _MbimNetPortManager        MbimNetPortManager;
typedef struct _MbimNetPortManagerClass   MbimNetPortManagerClass;
typedef struct _MbimNetPortManagerPrivate MbimNetPortManagerPrivate;

struct _MbimNetPortManager {
    GObject                    parent;
    MbimNetPortManagerPrivate *priv;
};

struct _MbimNetPortManagerClass {
    GObjectClass parent;

    gboolean (* list_links) (MbimNetPortManager  *self,
                             const gchar         *base_ifname,
                             GPtrArray          **out_links,
                             GError             **error);

    void     (* add_link)        (MbimNetPortManager  *self,
                                  guint                session_id,
                                  const gchar         *base_ifname,
                                  const gchar         *ifname_prefix,
                                  guint                timeout,
                                  GCancellable        *cancellable,
                                  GAsyncReadyCallback  callback,
                                  gpointer             user_data);
    gchar *  (* add_link_finish) (MbimNetPortManager  *self,
                                  guint               *session_id,
                                  GAsyncResult        *res,
                                  GError             **error);

    void     (* del_link)        (MbimNetPortManager   *self,
                                  const gchar          *ifname,
                                  guint                 timeout,
                                  GCancellable         *cancellable,
                                  GAsyncReadyCallback   callback,
                                  gpointer              user_data);
    gboolean (* del_link_finish) (MbimNetPortManager   *self,
                                  GAsyncResult         *res,
                                  GError              **error);

    void     (* del_all_links)        (MbimNetPortManager   *self,
                                       const gchar          *base_ifname,
                                       GCancellable         *cancellable,
                                       GAsyncReadyCallback   callback,
                                       gpointer              user_data);
    gboolean (* del_all_links_finish) (MbimNetPortManager   *self,
                                       GAsyncResult         *res,
                                       GError              **error);
};

GType mbim_net_port_manager_get_type (void);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (MbimNetPortManager, g_object_unref)

gboolean  mbim_net_port_manager_list_links (MbimNetPortManager  *self,
                                            const gchar         *base_ifname,
                                            GPtrArray          **out_links,
                                            GError             **error);

void      mbim_net_port_manager_add_link        (MbimNetPortManager   *self,
                                                 guint                 session_id,
                                                 const gchar          *base_ifname,
                                                 const gchar          *ifname_prefix,
                                                 guint                 timeout,
                                                 GCancellable         *cancellable,
                                                 GAsyncReadyCallback   callback,
                                                 gpointer              user_data);
gchar    *mbim_net_port_manager_add_link_finish (MbimNetPortManager   *self,
                                                 guint                *session_id,
                                                 GAsyncResult         *res,
                                                 GError              **error);

void      mbim_net_port_manager_del_link        (MbimNetPortManager   *self,
                                                 const gchar          *ifname,
                                                 guint                 timeout,
                                                 GCancellable         *cancellable,
                                                 GAsyncReadyCallback   callback,
                                                 gpointer              user_data);
gboolean  mbim_net_port_manager_del_link_finish (MbimNetPortManager   *self,
                                                 GAsyncResult         *res,
                                                 GError              **error);

void      mbim_net_port_manager_del_all_links        (MbimNetPortManager   *self,
                                                      const gchar          *base_ifname,
                                                      GCancellable         *cancellable,
                                                      GAsyncReadyCallback   callback,
                                                      gpointer              user_data);
gboolean  mbim_net_port_manager_del_all_links_finish (MbimNetPortManager   *self,
                                                      GAsyncResult         *res,
                                                      GError              **error);

GHashTable *mbim_net_port_manager_peek_transactions (MbimNetPortManager *self);

gchar *mbim_net_port_manager_peek_iface (MbimNetPortManager *self);

guint *mbim_net_port_manager_peek_current_sequence_id (MbimNetPortManager *self);

GSocket *mbim_net_port_manager_peek_socket (MbimNetPortManager *self);

void mbim_net_port_manager_common_setup (MbimNetPortManager *self,
                                         const gchar        *iface,
                                         GSocket            *gsocket);

gchar *mbim_net_port_manager_util_session_id_to_ifname (const gchar *ifname_prefix,
                                                        guint        session_id);

gboolean mbim_net_port_manager_util_get_first_free_session_id (const gchar *ifname_prefix,
                                                               guint       *session_id);

#endif /* _LIBMBIM_GLIB_MBIM_NET_PORT_MANAGER_H_ */
