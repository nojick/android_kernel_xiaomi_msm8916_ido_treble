#ifndef ISCSI_TARGET_TPG_H
#define ISCSI_TARGET_TPG_H

extern struct iscsi_portal_group *iscsit_alloc_portal_group(struct iscsi_tiqn *, u16);
extern int iscsit_load_discovery_tpg(void);
extern void iscsit_release_discovery_tpg(void);
extern struct iscsi_portal_group *iscsit_get_tpg_from_np(struct iscsi_tiqn *,
			struct iscsi_np *);
extern int iscsit_get_tpg(struct iscsi_portal_group *);
extern void iscsit_put_tpg(struct iscsi_portal_group *);
extern void iscsit_clear_tpg_np_login_threads(struct iscsi_portal_group *, bool);
extern void iscsit_tpg_dump_params(struct iscsi_portal_group *);
extern int iscsit_tpg_add_portal_group(struct iscsi_tiqn *, struct iscsi_portal_group *);
extern int iscsit_tpg_del_portal_group(struct iscsi_tiqn *, struct iscsi_portal_group *,
			int);
extern int iscsit_tpg_enable_portal_group(struct iscsi_portal_group *);
extern int iscsit_tpg_disable_portal_group(struct iscsi_portal_group *, int);
extern struct iscsi_node_acl *iscsit_tpg_add_initiator_node_acl(
			struct iscsi_portal_group *, const char *, u32);
extern void iscsit_tpg_del_initiator_node_acl(struct iscsi_portal_group *,
			struct se_node_acl *);
extern struct iscsi_node_attrib *iscsit_tpg_get_node_attrib(struct iscsi_session *);
extern void iscsit_tpg_del_external_nps(struct iscsi_tpg_np *);
extern struct iscsi_tpg_np *iscsit_tpg_locate_child_np(struct iscsi_tpg_np *, int);
extern struct iscsi_tpg_np *iscsit_tpg_add_network_portal(struct iscsi_portal_group *,
			struct __kernel_sockaddr_storage *, char *, struct iscsi_tpg_np *,
			int);
extern int iscsit_tpg_del_network_portal(struct iscsi_portal_group *,
			struct iscsi_tpg_np *);
extern int iscsit_tpg_set_initiator_node_queue_depth(struct iscsi_portal_group *,
			unsigned char *, u32, int);
extern int iscsit_ta_authentication(struct iscsi_portal_group *, u32);
extern int iscsit_ta_login_timeout(struct iscsi_portal_group *, u32);
extern int iscsit_ta_netif_timeout(struct iscsi_portal_group *, u32);
extern int iscsit_ta_generate_node_acls(struct iscsi_portal_group *, u32);
extern int iscsit_ta_default_cmdsn_depth(struct iscsi_portal_group *, u32);
extern int iscsit_ta_cache_dynamic_acls(struct iscsi_portal_group *, u32);
extern int iscsit_ta_demo_mode_write_protect(struct iscsi_portal_group *, u32);
extern int iscsit_ta_prod_mode_write_protect(struct iscsi_portal_group *, u32);

#endif /* ISCSI_TARGET_TPG_H */
