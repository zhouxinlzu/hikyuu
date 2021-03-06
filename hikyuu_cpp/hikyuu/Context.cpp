/*
 * Context.cpp
 *
 *  Created on: 2019-03-09
 *      Author: fasiondog
 */

#include "Context.h"

namespace hku {

static Parameter g_hikyuu_context;


void HKU_API setGlobalContext(const Stock& stock, const KQuery& query) {
    if (stock.isNull()) {
        g_hikyuu_context.set<KData>("kdata", KData());
    } else {
        g_hikyuu_context.set<KData>("kdata", stock.getKData(query));
    }
}

void HKU_API setGlobalContext(const KData& k) {
    g_hikyuu_context.set<KData>("kdata", k);
}

KData HKU_API getGlobalContextKData() {
    return g_hikyuu_context.get<KData>("kdata");
}

} /* namespace */
