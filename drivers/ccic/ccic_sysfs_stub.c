// Stub for ccic_sysfs when full CCIC hardware (S2MM005) is not present
#include <linux/sysfs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>

static struct attribute *ccic_sysfs_attrs[] = {
	NULL,
};

const struct attribute_group ccic_sysfs_group = {
	.attrs = ccic_sysfs_attrs,
};

// Weak stub for select_pdo — overridden by usbpd_manager.o if USE_CCIC is enabled
int __weak select_pdo(int num)
{
	return -ENOSYS;
}
EXPORT_SYMBOL(select_pdo);

// Stubs for PMU shared reg when MCU_IPC is disabled (WiFi-only device)
#if !defined(CONFIG_MCU_IPC)
int exynos_pmu_shared_reg_enable(void)
{
	return 0;
}
EXPORT_SYMBOL(exynos_pmu_shared_reg_enable);

void exynos_pmu_shared_reg_disable(void)
{
}
EXPORT_SYMBOL(exynos_pmu_shared_reg_disable);
#endif

// Stub for watchdog emergency reset when EXYNOS_SNAPSHOT_WATCHDOG_RESET is not enabled
#if !defined(CONFIG_EXYNOS_SNAPSHOT_WATCHDOG_RESET)
int s3c2410wdt_set_emergency_reset(unsigned int timeout_cnt)
{
	return 0;
}
EXPORT_SYMBOL(s3c2410wdt_set_emergency_reset);
#endif
