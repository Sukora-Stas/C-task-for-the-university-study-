//------------------------------------------------------------------------------
// <auto-generated>
//     Этот код создан по шаблону.
//
//     Изменения, вносимые в этот файл вручную, могут привести к непредвиденной работе приложения.
//     Изменения, вносимые в этот файл вручную, будут перезаписаны при повторном создании кода.
// </auto-generated>
//------------------------------------------------------------------------------

namespace YIP
{
    using System;
    using System.Collections.Generic;
    
    public partial class Заказ
    {
        public int Номер_заказа { get; set; }
        public int Количество_продукции { get; set; }
        public int Код_продукции { get; set; }
        public int Номер_договора { get; set; }
    
        public virtual Договор Договор { get; set; }
        public virtual Печатная_продукция Печатная_продукция { get; set; }
    }
}
