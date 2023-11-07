import { parse } from "date-fns";
import { format, utcToZonedTime, zonedTimeToUtc } from "date-fns-tz";

export class Util {

    static fromIsoDate(dateTime: string): Date {
        const localDate = parse(dateTime, "yyyy-MM-dd'T'HH:mm'Z", new Date());
        return zonedTimeToUtc(localDate, "UTC");
    }

    static toIsoDate(date: Date): string {
        const utcDate = utcToZonedTime(date, "UTC");
        return format(utcDate, "yyyy-MM-dd'T'HH:mm'Z'", { timeZone: "UTC" });
    }

}
