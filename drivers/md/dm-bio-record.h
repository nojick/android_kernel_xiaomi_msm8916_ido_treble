/*
 * Copyright (C) 2004-2005 Red Hat, Inc. All rights reserved.
 *
 * This file is released under the GPL.
 */

#ifndef DM_BIO_RECORD_H
#define DM_BIO_RECORD_H

#include <linux/bio.h>

/*
 * There are lots of mutable fields in the bio struct that get
 * changed by the lower levels of the block layer.  Some targets,
 * such as multipath, may wish to resubmit a bio on error.  The
 * functions in this file help the target record and restore the
 * original bio state.
 */

struct dm_bio_vec_details {
#if PAGE_SIZE < 65536
	__u16 bv_len;
	__u16 bv_offset;
#else
	unsigned bv_len;
	unsigned bv_offset;
#endif
};

struct dm_bio_details {
	struct block_device *bi_bdev;
	unsigned long bi_flags;
	struct bvec_iter bi_iter;
	struct dm_bio_vec_details bi_io_vec[BIO_MAX_PAGES];
};

static inline void dm_bio_record(struct dm_bio_details *bd, struct bio *bio)
{
	unsigned i;

	bd->bi_bdev = bio->bi_bdev;
	bd->bi_flags = bio->bi_flags;
	bd->bi_iter = bio->bi_iter;

	for (i = 0; i < bio->bi_vcnt; i++) {
		bd->bi_io_vec[i].bv_len = bio->bi_io_vec[i].bv_len;
		bd->bi_io_vec[i].bv_offset = bio->bi_io_vec[i].bv_offset;
	}
}

static inline void dm_bio_restore(struct dm_bio_details *bd, struct bio *bio)
{
	unsigned i;

	bio->bi_bdev = bd->bi_bdev;
	bio->bi_flags = bd->bi_flags;
	bio->bi_iter = bd->bi_iter;

	for (i = 0; i < bio->bi_vcnt; i++) {
		bio->bi_io_vec[i].bv_len = bd->bi_io_vec[i].bv_len;
		bio->bi_io_vec[i].bv_offset = bd->bi_io_vec[i].bv_offset;
	}
}

#endif
