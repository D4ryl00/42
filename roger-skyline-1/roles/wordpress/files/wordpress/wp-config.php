<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'wordpress');

/** MySQL database username */
define('DB_USER', 'wordpress');

/** MySQL database password */
define('DB_PASSWORD', 'wordpress');

/** MySQL hostname */
define('DB_HOST', 'localhost');

/** Database Charset to use in creating database tables. */
define('DB_CHARSET', 'utf8mb4');

/** The Database Collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '16U.FF1m7S59$Vkg`c {s{}nEazpRbM`cRxp3JU>Op:s5 t4zUe|,iEP-0~p,XYI');
define('SECURE_AUTH_KEY',  '|uc=tLCepg(]3;`#K|b:bHaBv*7p<Kojs]@:GPHp*%S(?/n^q`xBrdz:^6uKMyqy');
define('LOGGED_IN_KEY',    'UzdxHJGi<GzU*Ptzk z.KJOKu1&>vw3s9X=@[vkK(A8K[N0ZYYm$65FuC,<>;lZD');
define('NONCE_KEY',        'zLqqj^Gd21;GlU4F)),Hty:gr8HY!Y?EJVp5qR03X/(|v(H5VfFYr41L1^S8c~~E');
define('AUTH_SALT',        'N3Wd4h@x7 I~5lAj,I)1fiz,VY`70nHGTbl%um#~!>=k{u]^k-nt>?fD= w2@0pv');
define('SECURE_AUTH_SALT', 'b:@SxE=s[-c_<T3St5;gMMw(Q^4G_NCYH0/O^G!hAaOfl+Y/A!5?;~&NBl,n=<34');
define('LOGGED_IN_SALT',   'Mc~noCRSv;!6JlXP!Y.Kbe?iFPYq`Y]X]RW<!(buA}})9 4Mk8nSz`T7kI}5U/Lx');
define('NONCE_SALT',       'R(b&3[fkD|{O?jGt^um?@zhYRm]}h!+u]U&Ezz7sg3EPL)tpy0zydlr]5wQq!WQ4');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix  = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define('WP_DEBUG', false);

/* That's all, stop editing! Happy blogging. */

/** Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');
